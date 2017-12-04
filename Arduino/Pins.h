/**
 * @file Pins.h
 * @brief class with definitions pins
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#ifndef Pins_h
#define Pins_h

#include "Arduino.h"

/**
 * \defgroup const pins
 * @{
 */
#define BTN_LIGHT_PIN     3   ///< button to manual control light relay
#define DS18B20_PIN 		  5   ///< thermometer
#define DHT22_PIN  			  4   ///< thermometer and air humidity sensor
#define TANK_ECHO_PIN  		6   ///< tank lvel sensor echo
#define TANK_TRIG_PIN  		7   ///< tank lvel sensor triger
#define ERR_LED_PIN       10  ///< error led
#define LIGHT_RELAY_PIN  	11  ///< litght relay
#define PUMP_RELAY_PIN  	12  ///< pump relay
#define LIGHT_MESURE_PIN  14  ///< light sensor
/**@}*/

#endif
