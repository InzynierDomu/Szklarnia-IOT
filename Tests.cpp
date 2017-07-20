#include "Arduino.h"
#include "Tests.h"

bool Tests::DistanceToHighDifference(int distance, int &avarageValue)
{
  bool correct = true;
  if (distance != constrain(distance, avarageValue - maxDifferenceDistance, avarageValue + maxDifferenceDistance))correct = false;
  return correct;
}

bool Tests::TempToHighDifference(float temp, float &avarageValue)
{
	bool correct = true;
	if (temp != constrain(temp, avarageValue - maxDifferenceTemp, avarageValue + maxDifferenceTemp))correct = false;
	return correct;
}

bool Tests::DistanceMaxMin(int distance)
{
	bool correct = true;
	if (distance > 100 && distance < 0)correct = false;
	return correct;
}

bool Tests::LightToHighDifference(int light, int &avarageValue)
{
  bool correct = true;
  if (light != constrain(light, avarageValue - maxDifferenceLight, avarageValue + maxDifferenceLight))correct = false; 
  return correct;
}

bool Tests::HumToHighDifference(int humidity, int &avarageValue)
{
  bool correct = true;
  if (humidity != constrain(humidity, avarageValue - maxDifferenceHum, avarageValue + maxDifferenceHum))correct = false; 
  return correct;
}

