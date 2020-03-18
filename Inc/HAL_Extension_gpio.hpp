#ifndef HAL_EXTENSION_GPIO_HPP
#define HAL_EXTENSION_GPIO_HPP

#ifdef __gpio_H

#include "HAL_Extension_util.hpp"
#include <vector>

namespace {
	uint8_t lightDataTable[17] = {
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
}

class GPIO {
private:
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
public:
    GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin){

    }

    GPIO_PinState read(){
        return gpioRead(GPIOx, GPIO_Pin);
    }

    bool readBool(){
    	return read() == GPIO_PIN_SET;
    }

    void write(GPIO_PinState PinState){
        gpioWrite(GPIOx, GPIO_Pin, PinState);
    }

    void set(){
        write(GPIO_PIN_SET);
    }

    void reset(){
        write(GPIO_PIN_RESET);
    }

    void toggle(){
        gpioToggle(GPIOx, GPIO_Pin);
    }
};

class DIPSwitch {
private:
    std::vector<GPIO> list;
    bool flip;
public:
    DIPSwitch(bool flip = false): flip(flip) {
        list.reserve(7);
    }

    DIPSwitch& add(GPIO gpio){
        if(getSize() < 7){
        	list.push_back(gpio);
        }
        return *this;
    }

    DIPSwitch& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
        return add(GPIO(GPIOx, GPIO_Pin));
    }

    uint8_t getSize(){
        return list.size();
    }

    uint8_t getAddress(){
        uint8_t builder = 0;
        for(int i = 0; i < getSize(); i++){
            builder |= list[i].read() << i;
        }
        return flip? ~builder : builder;
    }
};

class SevenSegment {
private:
	std::vector<GPIO> list;
    bool flip;
public:
	SevenSegment(bool flip = false): flip(flip) {
		list.reserve(8);
	}

	SevenSegment& add(GPIO gpio){
		if(!isAvailable()){
			list.push_back(gpio);
		}
		return *this;
	}

	SevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
		return add(GPIO(GPIOx, GPIO_Pin));
	}

	bool setLight(uint8_t lightData){
		if(!isAvailable()) return false;
		uint8_t mask = 1;
		for(auto segment : list){
			uint8_t outData = lightData & mask;
			segment.write((GPIO_PinState) (flip? ~outData : outData));
			mask <<= 1;
		}
		return true;
	}

	bool set(int8_t hex, bool point = false){
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

	bool clear(){
		return setLight(0);
	}

	bool isAvailable(){
		return list.size() == 8;
	}
};

class FixedSevenSegment: public SevenSegment {
private:
	GPIO pointGpio = nullptr;
public:
	FixedSevenSegment() override {
		list.reserve(4);
	}

	FixedSevenSegment& add(GPIO gpio) override {
		if(!isAvailable()){
			list.push_back(gpio);
		}
		return *this;
	}

	FixedSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) override {
		return add(GPIO(GPIOx, GPIO_Pin));
	}

	bool setLight(uint8_t lightData) override {
		return set(lightData & 0xF, lightData & 0x10);
	}

	bool set(int8_t hex, bool point = false) override {
		if(isAvailable()){
			if(point && pointGpio != nullptr){
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

	bool clear() override {
		return set(0);
	}

	bool isAvailable() override {
		return list.size() == 4;
	}
};

class DynamicSevenSegment {
private:
	SevenSegment sevenSegment;
	std::vector<GPIO> digitList;
	uint8_t digitCursor;
	std::vector<int8_t> splitNum;
	uint8_t system;
	bool zeroFill;
	bool allowSign;
	bool isStop = true;
public:
	DynamicSevenSegment(SevenSegment sevenSegment, bool hex = false, bool zeroFill = false, bool allowSign = false): sevenSegment(sevenSegment), zeroFill(zeroFill), allowSign(allowSign){
		system = hex? 16 : 10;
	}

	DynamicSevenSegment& add(GPIO gpio){
		list.push_back(gpio);
		return *this;
	}

	DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
		return add(GPIO(GPIOx, GPIO_Pin));
	}

	void update(int64_t num){
		splitNum.clear();
		bool isMinus = num < 0;
		if(isMinus){
			num *= -1;
		}
		do {
			splitNum.push_back((int8_t)(num % system));
			num /= system;
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
	}

	void next(){
		if(isStop) return;
		digitList[digitCursor].reset();
		digitCursor ++;
		if(splitNum.size() <= digitCursor || digitList.size() <= digitCursor){
			digitCursor = 0;
		}
		sevenSegment.set(splitNum[digitCursor]);
		digitList[digitCursor].set();
	}

	void stop(){
		isStop = true;
		sevenSegment.clear();
		digitList[digitCursor].reset();
	}
};

#endif // __gpio_H

#endif
