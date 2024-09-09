#include "Device_Test.h"
#include "allocateMem.h"
#include "commandmessenger.h"
#include <FastLED.h>

#define LED_PIN 4
#define NUM_LEDS 20 // 150 LEDs in the full strip

CRGB leds[NUM_LEDS];

/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */

Device_Test::Device_Test(uint8_t Pin1, uint8_t Pin2)
{
    _pin1 = Pin1;
    _pin2 = Pin2;
}

void Device_Test::begin()
{
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  leds[LEDPosition] = CRGB::White;
  FastLED.show();
}

void Device_Test::attach(uint16_t Pin3, char *init)
{
    _pin3 = Pin3;
}

void Device_Test::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void Device_Test::set(int16_t messageID, char *setPoint)
{
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    // int32_t  data = atoi(setPoint);
    // uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
    case -2:
        // tbd., get's called when PowerSavingMode is entered
    case 0:
        // output = (uint16_t)data;
        // data   = output;
        setLEDPosition(atof(setPoint));
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void Device_Test::update()
{
    // Do something which is required regulary
    if(prevLEDPosition != LEDPosition)
    {
        prevLEDPosition = LEDPosition;
        FastLED.clear();
        FastLED.show();
        leds[LEDPosition] = CRGB::White;
        FastLED.show();

    }
}

void Device_Test::setLEDPosition(float value)
{
    LEDPosition = scaleValue(value, -1.0, 1.0, 0, 19);
}

float Device_Test::scaleValue(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}