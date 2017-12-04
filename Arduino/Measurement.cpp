/**
 * @file Measurement.cpp
 * @brief class with handler mapping sensors
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include "Arduino.h"
#include "Measurement.h"
#include <OneWire.h>
#include <DS18B20.h>
#include "Pins.h"

//#define DEBUG

/**
 * @brief constructor
 * @param firstLoop: first main loop status
 */
Measurement::Measurement(bool &firstLoop)
{
  _firstLoop = firstLoop; 
}

/**
 * @brief measure liquid level in tank
 * @param avarageValue: avarage liquid level
 * @param counterErr: counter for liquid level sensor error
 */
void Measurement::MeasurementTank(int &avarageValue, int &counterErr)
{
  int procentDistance = 0;
  int _avarageValue = avarageValue;
  
  int distance = Measurementdistance();
#ifdef DEBUG
  Serial.print("now distance in tank: ");
  Serial.println(distance);
#endif  
  procentDistance = ((distance - minDistance)*100)/(maxDistance-minDistance); 
  
  if (test.DistanceMaxMin(procentDistance) == false) counterErr++;

  if (_firstLoop)
  {
    avarageValue = procentDistance;
  }else{
    avarageValue = (5 * avarageValue + procentDistance) / 6;
    if (test.DistanceToHighDiff(procentDistance, _avarageValue) == false) counterErr++;
  }
}

/**
 * @brief measure temperature
 * @param avarageValue: avarage temperature value 
 * @param counterErr: counter for thermometer error
 */
void Measurement::MeasurementTemp(float &avarageValue, int &counterErr)
{
  float nowTemp;
  float _avarageValue = avarageValue;

  OneWire onewire(DS18B20_PIN);
  DS18B20 sensors(&onewire);
  sensors.begin();

  sensors.request(ds18b20Address);
  while (!sensors.available()); 
  nowTemp = sensors.readTemperature(ds18b20Address);
  //TODO: zglaszanie bledow od nieudanego pomiaru

#ifdef DEBUG
  Serial.print("now temp: ");
  Serial.println(nowTemp);
#endif  
  
  if (_firstLoop){
    avarageValue = nowTemp;
  }else{
    avarageValue = (10 * avarageValue + nowTemp) / 11;
    if (test.TempToHighDiff(nowTemp, _avarageValue) == false) counterErr++;
  }
}

/**
 * @brief measure light intensity
 * @param avarageValue: avarage light intensity value 
 * @param counterErr: counter for light sensor error
 */
void Measurement::MeasurementLight(int &avarageValue, int &counterErr)
{
  int _avarageValue = avarageValue;
  //TODO: odwrotny pomiar, im ciemniej tym wieksza wartosc, blad od malego zasloniecia -> korekcja wartosci 
  int nowLight = analogRead(LIGHT_MESURE_PIN);
  
#ifdef DEBUG
  Serial.print("now light: ");
  Serial.println(nowLight);
#endif 
  
  if (_firstLoop){
    avarageValue = nowLight;
    }else{
    avarageValue = (20 * avarageValue + nowLight) / 21;
    if (test.LightToHighDiff(nowLight, _avarageValue) == false) counterErr++;
  }
}

/**
 * @brief measure air humidity
 * @param avarageValue: avarage air humidity value
 * @param counterErr: counter for humidity sensor error
 */
void Measurement::MeasurementHum(int &avarageValue, int &counterErr)
{
  int _avarageValue = avarageValue;
  //TODO: pomiar
  int nowHumidity = 0; 

#ifdef DEBUG
  Serial.print("now hum: ");
  Serial.println(nowHumidity);
#endif 

  if (_firstLoop){
    avarageValue = nowHumidity;
  }else{
    avarageValue = (5 * avarageValue + nowHumidity) / 6;
    if (test.LightToHighDiff(nowHumidity, _avarageValue) == false) counterErr++;
  }
}

/**
 * @brief measure liquid level in tank
 * @return liquid level in tank
 */
int Measurement::Measurementdistance()
{
  pinMode(TANK_TRIG_PIN, OUTPUT); 
  pinMode(TANK_ECHO_PIN, INPUT); 

  long moment;
  long distance;
  
  digitalWrite(TANK_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TANK_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TANK_TRIG_PIN, LOW); 
  moment = pulseIn(TANK_ECHO_PIN, HIGH);
  distance = moment / 58;   
  return distance;
}
