#ifdef HAL_GPIO_MODULE_ENABLED

#ifndef HAL_EXTENSION_GPIO_HPP
#define HAL_EXTENSION_GPIO_HPP

#include "gpio.h"
#include <vector>
#include <array>

class GPIO {
private:
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
public:
    GPIO();
    GPIO(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    GPIO_PinState read();
    bool isSet();
    bool isReset();
    void write(GPIO_PinState PinState);
    void set();
    void reset();
    void toggle();
};

class DIPSwitch {
private:
    std::vector<GPIO> list;
    bool flip;
public:
    DIPSwitch(bool flip = false);
    DIPSwitch& add(GPIO gpio);
    DIPSwitch& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    uint8_t getSize();
    uint8_t getAddress();
};

class SevenSegment {
private:
	std::vector<GPIO> list;
	bool flip;
	bool enablePoint = false;
	GPIO pointGpio;
public:
	SevenSegment(bool flip = false);
	virtual SevenSegment& add(GPIO gpio);
	virtual SevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
	virtual bool setLight(uint8_t lightData);
	virtual bool set(int8_t hex, bool point = false);
	virtual bool clear();
	virtual bool isAvailable();
};

class FixedSevenSegment: public SevenSegment {
private:
	std::vector<GPIO> list;
	bool flip;
	bool enablePoint = false;
	GPIO pointGpio;
public:
	FixedSevenSegment(bool flip = false);
	FixedSevenSegment& add(GPIO gpio);
	FixedSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) override;
	bool setLight(uint8_t lightData) override;
	bool set(int8_t hex, bool point = false) override;
	bool clear() override;
	bool isAvailable() override;
};

class DynamicSevenSegment {
private:
	SevenSegment sevenSegment;
	std::vector<GPIO> digitList;
	uint8_t digitCursor = 0;
	std::vector<int8_t> splitNum;
	uint8_t digitSystem;
	bool zeroFill;
	bool allowSign;
	bool isStop = true;
	uint8_t point = 0;
	void update(int64_t num, uint8_t point);
public:
	DynamicSevenSegment();
	DynamicSevenSegment(SevenSegment sevenSegment, bool hex = false, bool zeroFill = false, bool allowSign = false);
	DynamicSevenSegment& add(GPIO gpio);
	DynamicSevenSegment& add(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
	void update(int64_t num);
	void updateFixedPoint(float num, uint8_t point);
	void updateFloatPoint(float num);
	void next();
	void stop();
};

#endif // HAL_EXTENSION_GPIO_HPP

#endif // HAL_GPIO_MODULE_ENABLED
