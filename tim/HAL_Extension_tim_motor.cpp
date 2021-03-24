#ifndef CONFIG_DISABLE_MODULE_TIM

#include "tim/HAL_Extension_tim_motor.hpp"

namespace halex {

Motor::Motor(): Motor(PWM(), PWM()) {}

Motor::Motor(const PWM &positive, const PWM &negative): positive(positive), negative(negative) {

}

Motor::Motor(TIM_HandleTypeDef *htimPos, uint32_t channelPos, TIM_HandleTypeDef *htimNeg, uint32_t channelNeg): Motor(PWM(htimPos, channelPos), PWM(htimNeg, channelNeg)) {

}

Motor::Motor(TIM_HandleTypeDef &htimPos, uint32_t channelPos, TIM_HandleTypeDef &htimNeg, uint32_t channelNeg): Motor(&htimPos, channelPos, &htimNeg, channelNeg) {

}

void Motor::start() noexcept {
    positive.start();
    negative.start();
}

void Motor::stop() noexcept {
    positive.stop();
    negative.stop();
}

void Motor::setCompare(uint32_t comparePos, uint32_t compareNeg) noexcept {
    positive.setCompare(comparePos);
    negative.setCompare(compareNeg);
}

void Motor::setSpeed(bool forward, uint32_t compare) noexcept {
    if(forward) {
        setCompare(compare, 0);
    } else {
        setCompare(0, compare);
    }
}

void Motor::setSpeed(bool forward, uint16_t numerator, uint16_t denominator) noexcept {
    if(forward) {
        positive.setCompare(numerator, denominator);
        negative.setCompare(0);
    } else {
        positive.setCompare(0);
        negative.setCompare(numerator, denominator);
    }
}

void Motor::setSpeed(int64_t speed) noexcept {
    bool forward = 0 < speed;
    setSpeed(forward, (uint32_t) (forward? speed : -speed));
}

void Motor::setSpeed(int16_t numerator, int16_t denominator) noexcept {
    bool forward = true;
    uint16_t abs_numerator;
    if(numerator < 0) {
        abs_numerator = (uint16_t) -numerator;
        forward = !forward;
    } else {
        abs_numerator = (uint16_t) numerator;
    }
    uint16_t abs_denominator;
    if(denominator < 0) {
        abs_denominator = (uint16_t) -denominator;
        forward = !forward;
    } else {
        abs_denominator = (uint16_t) denominator;
    }
    setSpeed(forward, abs_numerator, abs_denominator);
}

} // namespace halex

#endif // CONFIG_DISABLE_MODULE_TIM
