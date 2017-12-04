/**
 * @file Measurement.h
 * @brief class with handler mapping sensors
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#ifndef Measurement_h
#define Measurement_h

#include "Tests.h"

/**
 * @brief handler mapping sensors
 */
class Measurement
{
  public:
    Measurement(bool &firstLoop);                                 ///< constructor
    void MeasurementTank(int &avarageValue, int &counterErr);     ///< measure liquid level in tank
    void MeasurementTemp(float &avarageValue, int &counterErr);   ///< measure temperature
    void MeasurementLight(int &avarageValue, int &counterErr);    ///< measure light intensity
    void MeasurementHum(int &avarageValue, int &counterErr);      ///< measure air humidity
  private:
    const byte ds18b20Address[8]= {0x28, 0xE3, 0xE2, 0x22, 0x6, 0x0, 0x0, 0x91};  ///< ds18b20 thermometer one wire adress
        
    const int minDistance = 8;    ///< measurement recalculated for 0 percent
    const int maxDistance = 27;   ///< measurement recalculated for 100 percent
    
    Tests test;           ///< cheking measurements methods
    bool _firstLoop;      ///< first main loop flag 
  
    int Measurementdistance();    ///< measure liquid level in tank
};

#endif

