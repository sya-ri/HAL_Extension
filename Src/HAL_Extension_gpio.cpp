#include "HAL_Extension_gpio.hpp"
#include "HAL_Extension_util.hpp"
#include <cmath>

namespace {
	const std::array<const uint8_t, 17> lightDataTable = {
		0b0111111, // 0x0
		0b0000110, // 0x1
		0b1011011, // 0x2
		0b1001111, // 0x3
		0b1100110, // 0x4
		0b1101101, // 0x5
		0b1111101, // 0x6
		0b0000111, // 0x7
		0b1111111, // 0x8
		0b1101111, // 0x9
		0b1110111, // 0xA
		0b1111100, // 0xB
		0b0111001, // 0xC
		0b1011110, // 0xD
		0b1111001, // 0xE
		0b1110001, // 0xF
		0b1000000  //  -
	};

	uint8_t getNumberOfDigit(float num){
	    uint64_t numAsUInt = (uint64_t) ((num < 0)? -num : num);
	    uint64_t compare = 10;
	    uint8_t numberOfDigit = 1;
	    while(!(numAsUInt < compare)){
	        compare *= 10;
	        numberOfDigit ++;
	    }
	    return numberOfDigit;
	}
}

GPIO::GPIO(){}

GPIO::GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){

}

GPIO_PinState GPIO::read(){
	return gpioRead(GPIOx, GPIO_Pin);
}

bool GPIO::readBool(){
	return read() == GPIO_PIN_SET;
}

void GPIO::write(GPIO_PinState PinState){
	gpioWrite(GPIOx, GPIO_Pin, PinState);
}

void GPIO::set(){
	write(GPIO_PIN_SET);
}

void GPIO::reset(){
	write(GPIO_PIN_RESET);
}

void GPIO::toggle(){
	gpioToggle(GPIOx, GPIO_Pin);
}

DIPSwitch::DIPSwitch(bool flip): flip(flip) {
	list.reserve(7);
}

DIPSwitch& DIPSwitch::add(GPIO gpio){
	if(getSize() < 7){
		list.push_back(gpio);
	}
	return *this;
}

DIPSwitch& DIPSwitch::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	return add(GPIO(GPIOx, GPIO_Pin));
}

uint8_t DIPSwitch::getSize(){
	return list.size();
}

uint8_t DIPSwitch::getAddress(){
	uint8_t builder = 0;
	for(int i = 0; i < getSize(); i++){
		builder |= list[i].read() << i;
	}
	return flip? ~builder : builder;
}

SevenSegment::SevenSegment(bool flip): flip(flip) {
	list.reserve(7);
}

SevenSegment& SevenSegment::add(GPIO gpio){
	if(!isAvailable()){
		list.push_back(gpio);
	} else if(!enablePoint) {
		pointGpio = gpio;
		enablePoint = true;
	}
	return *this;
}

SevenSegment& SevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	return add(GPIO(GPIOx, GPIO_Pin));
}

bool SevenSegment::setLight(uint8_t lightData){
	if(!isAvailable()) return false;
	uint8_t mask = 1;
	for(auto segment : list){
		uint8_t outData = lightData & mask;
		segment.write((GPIO_PinState) (flip? ~outData : outData));
		mask <<= 1;
	}
	if(enablePoint){
		uint8_t outData = lightData & mask;
		pointGpio.write((GPIO_PinState) (flip? ~outData : outData));
	}
	return true;
}

bool SevenSegment::set(int8_t hex, bool point){
	uint8_t lightData;
	if(hex < 0){
		lightData = lightDataTable[16];
	} else {
		lightData = lightDataTable[hex & 0xF];
	}
	if(point){
		lightData |= 1 << 7;
	}
	return setLight(lightData);
}

bool SevenSegment::clear(){
	return setLight(0);
}

bool SevenSegment::isAvailable(){
	return list.size() == 7;
}

FixedSevenSegment::FixedSevenSegment(bool flip): flip(flip) {
	list.reserve(4);
}

FixedSevenSegment& FixedSevenSegment::add(GPIO gpio) {
	if(!isAvailable()){
		list.push_back(gpio);
	} else if(!enablePoint) {
		pointGpio = gpio;
		enablePoint = true;
	}
	return *this;
}

FixedSevenSegment& FixedSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	return add(GPIO(GPIOx, GPIO_Pin));
}

bool FixedSevenSegment::setLight(uint8_t lightData){
	return set(lightData & 0xF, lightData & 0x10);
}

bool FixedSevenSegment::set(int8_t hex, bool point){
	if(isAvailable()){
		if(point && enablePoint){
			pointGpio.set();
		}
		for(int i = 0; i < 4; i++){
			uint8_t outData = hex & 1;
			list[i].write((GPIO_PinState) (flip? ~outData : outData));
			hex >>= 1;
		}
		return true;
	} else {
		return false;
	}
}

bool FixedSevenSegment::clear(){
	return set(0);
}

bool FixedSevenSegment::isAvailable(){
	return list.size() == 4;
}

DynamicSevenSegment::DynamicSevenSegment(){}

DynamicSevenSegment::DynamicSevenSegment(SevenSegment sevenSegment, bool hex, bool zeroFill, bool allowSign): sevenSegment(sevenSegment), zeroFill(zeroFill), allowSign(allowSign){
	digitSystem = hex? 16 : 10;
}

DynamicSevenSegment& DynamicSevenSegment::add(GPIO gpio){
	digitList.push_back(gpio);
	return *this;
}

DynamicSevenSegment& DynamicSevenSegment::add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	return add(GPIO(GPIOx, GPIO_Pin));
}

void DynamicSevenSegment::update(int64_t num, uint8_t point){
	splitNum.clear();
	bool isMinus = num < 0;
	if(isMinus){
		num *= -1;
	}
	do {
		splitNum.push_back((int8_t)(num % digitSystem));
		num /= digitSystem;
	} while(0 < num);
	if(zeroFill){
		int8_t fillNumber = digitList.size() - splitNum.size();
		if(allowSign){
			fillNumber --;
		}
		while(0 < fillNumber){
			splitNum.push_back(0);
			fillNumber --;
		}
	}
	if(allowSign && isMinus){
		splitNum.push_back(-1);
	}
	uint8_t numSize = splitNum.size();
	if(numSize != 0){
		digitCursor = numSize - 1;
		isStop = false;
	} else {
		isStop = true;
	}
	this->point = point;
}

void DynamicSevenSegment::update(int64_t num){
	update(num, UINT8_MAX);
}

void DynamicSevenSegment::updateFixedPoint(float num, uint8_t point){
	for(uint8_t i = 0; i < point; i++){
		num *= 10;
	}
	update((int64_t) num, digitList.size() - point);
}

void DynamicSevenSegment::updateFloatPoint(float num){
	updateFixedPoint(num, getNumberOfDigit(num));
}

void DynamicSevenSegment::next(){
	if(isStop) return;
	digitList[digitCursor].reset();
	digitCursor ++;
	if(splitNum.size() <= digitCursor || digitList.size() <= digitCursor){
		digitCursor = 0;
	}
	sevenSegment.set(splitNum[digitCursor], digitCursor == point);
	digitList[digitCursor].set();
}

void DynamicSevenSegment::stop(){
	isStop = true;
	sevenSegment.clear();
	digitList[digitCursor].reset();
}



