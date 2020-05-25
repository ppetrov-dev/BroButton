#include <Arduino.h>
#include "BroButton.h"

#define PIN_EncoderSw 4

BroButton _button = BroButton(PIN_EncoderSw);

void setup()
{
    Serial.begin(9600);
    Serial.println("Serial OK");

    _button.Init();
    _button.AttachOnClick([]() { Serial.println("Click"); });
    _button.AttachOnDoubleClick([]() { Serial.println("Double Click"); });
    _button.AttachOnLongPressStart([]() { Serial.println("Press Start"); });
    _button.AttachOnLongPressStop([]() { Serial.println("Press Stop"); });
}
void loop()
{
    _button.Tick();
}