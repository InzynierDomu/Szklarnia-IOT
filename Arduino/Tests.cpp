/**
 * @file Tests.cpp
 * @brief class with tests sensors for bad measurments
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include "Arduino.h"
#include "Tests.h"

/**
 * @brief check tank liquid sensor for max difference
 * @param distance: present distance measured
 * @param avarageValue: avarage distance value 
 * @return false if difference present and avarage value is to high
 */
bool Tests::DistanceToHighDiff(int distance, int &avarageValue)
{
  bool correct = true;
  if (distance != constrain(distance, avarageValue - maxDiffDistance, avarageValue + maxDiffDistance))correct = false;
  return correct;
}

/**
 * @brief check thermometer for max difference
 * @param temp: present temperature measured
 * @param avarageValue: avarage temperature value 
 * @return false if difference present and avarage value is to high
 */
bool Tests::TempToHighDiff(float temp, float &avarageValue)
{
  bool correct = true;
  if (temp != constrain(temp, avarageValue - maxDiffTemp, avarageValue + maxDiffTemp))correct = false;
  return correct;
}

/**
 * @brief check tank liquid sensor for min/max measurement
 * @param distance: present distance measured
 * @return false if measurement is to low or to high
 */
bool Tests::DistanceMaxMin(int distance)
{
  bool correct = true;
  if (distance > maxDistancePercent && distance < minDistancePercent)correct = false;
  return correct;
}

/**
 * @brief check light sensor for max difference
 * @param light: present light measured
 * @param avarageValue: avarage light value 
 * @return false if difference present and avarage value is to high
 */
bool Tests::LightToHighDiff(int light, int &avarageValue)
{
  bool correct = true;
  if (light != constrain(light, avarageValue - maxDiffLight, avarageValue + maxDiffLight))correct = false; 
  return correct;
}

/**
 * @brief check humidity sensor for max difference
 * @param humidity: present humidity measured
 * @param avarageValue: avarage humidity value 
 * @return false if difference present and avarage value is to high
 */
bool Tests::HumToHighDiff(int humidity, int &avarageValue)
{
  bool correct = true;
  if (humidity != constrain(humidity, avarageValue - maxDiffHum, avarageValue + maxDiffHum))correct = false; 
  return correct;
}

