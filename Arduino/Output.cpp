/**
 * @file Output.cpp
 * @brief class with handler mapping outputs
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include "Arduino.h"
#include "Output.h"
#include "Pins.h"

/**
 * @brief constructor
 */
Output::Output()
{
  pinMode(ERR_LED_PIN, OUTPUT); 
  pinMode(LIGHT_RELAY_PIN, OUTPUT); 
  pinMode(PUMP_RELAY_PIN , OUTPUT); 
}

/**
 * @brief set light relay state
 * @param state: expected state 
 */
void Output::SetLight(bool state)
{
  SetPinLvl(LIGHT_RELAY_PIN, state);
}

/**
 * @brief set pump relay state
 * @param state: expected state
 * @param timer: must be more than 0 to turn on pump
 */
void Output::SetPump(bool &state, int &timer)
{
  SetPinLvl(PUMP_RELAY_PIN, state);
  if (state && timer > 0){
    timer--;
  }
  else{
    state = false;
  }
}

/**
 * @brief set error led state
 * @param state: expected state 
 */
void Output::SetErrLed(bool state)
{
  SetPinLvl(ERR_LED_PIN, state);
}

/**
 * @brief set output pin state
 * @param pin: number GPIO pin to change state
 * @param state: expected pin state
 */
void Output::SetPinLvl(int pin, bool state)
{
  if(state) 
  {
    digitalWrite(pin, HIGH);
  }else{
    digitalWrite(pin, LOW);
  }
}
