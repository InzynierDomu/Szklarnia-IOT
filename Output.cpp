#include "Arduino.h"
#include "Output.h"
#include "Pins.h"

Output::Output()
{
  pinMode(ERR_LED_PIN, OUTPUT); 
  pinMode(LIGHT_RELAY_PIN, OUTPUT); 
  pinMode(PUMP_RELAY_PIN , OUTPUT); 
}

void Output::SetLight(bool state)
{
  SetPinLvl(LIGHT_RELAY_PIN, state);
}

void Output::SetPump(bool state)
{
  SetPinLvl(PUMP_RELAY_PIN, state);
}

void Output::SetErrLed(bool state)
{
  SetPinLvl(ERR_LED_PIN, state);
}

void Output::SetPinLvl(int pin, bool state)
{
  if(state) 
  {
    digitalWrite(pin, HIGH);
  }else{
    digitalWrite(pin, LOW);
  }
}
