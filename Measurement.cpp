#include "Arduino.h"
#include "Measurement.h"
#include <OneWire.h>
#include <DS18B20.h>
#include "Pins.h"

#define DEBUG

Measurement::Measurement(bool &firstLoop)
{
	_firstLoop = firstLoop; 
}

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
		if (test.DistanceToHighDifference(procentDistance, _avarageValue) == false) counterErr++;
	}
}

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
		if (test.TempToHighDifference(nowTemp, _avarageValue) == false) counterErr++;
  }
}

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
    if (test.LightToHighDifference(nowLight, _avarageValue) == false) counterErr++;
  }
}

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
    if (test.LightToHighDifference(nowHumidity, _avarageValue) == false) counterErr++;
  }
}

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
