#pragma once

#include "Arduino.h"

class Device_Test
{
public:
    Device_Test(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;

    uint16_t LEDPosition = 10;
    uint16_t prevLEDPosition = 10;

    float scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
    void setLEDPosition(float value);
};