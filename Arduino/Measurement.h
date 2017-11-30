/*
  GreenHouse IOT - Measurement
  Create by Szymon Markiewicz
  http://www.inzynierdomu.pl/
 */

#ifndef Measurement_h
#define Measurement_h

#include "Tests.h"

class Measurement
{
  public:
    Measurement(bool &firstLoop);
    void MeasurementTank(int &avarageValue, int &counterErr);
    void MeasurementTemp(float &avarageValue, int &counterErr);
    void MeasurementLight(int &avarageValue, int &counterErr);
    void MeasurementHum(int &avarageValue, int &counterErr); 
  private:
    const byte ds18b20Address[8]= {0x28, 0xE3, 0xE2, 0x22, 0x6, 0x0, 0x0, 0x91};
    const int minDistance = 8;
    const int maxDistance = 27;
    
    Tests test;
    bool _firstLoop;
  
    int Measurementdistance();
};

#endif

