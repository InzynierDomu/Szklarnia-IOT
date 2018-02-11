/**
 * @file Arduino.ino
 * @brief GreenHouse IOT - Main
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include "Measurement.h"
#include "Output.h"
#include "ESPCom.h"
#include "Pins.h"

//#define DEBUG

const int maxErrCnt = 5;          ///< counter after error appear
const int pumpOnTime = 10;        ///< time when pump turn on in reps main loop
const int tempMultiplier = 100;   ///< multiplier to convert float to int value 

bool firstLoop;       ///< frist loop flag
float averageTemp;    ///< avarage value of temperature
int avarageTank;      ///< avarge value of level liquid in tank
int avarageLight;     ///< avarage value of light intensity
int avarageHum;       ///< avarage value of air humidity
int error;            ///< error code
int errCnt_ds18b20;   ///< counter for error from thermometer
int errCnt_tank;      ///< counter for error from tank lvel sensor
int errCnt_light;     ///< counter for error from light sensor
int errCnt_hum;       ///< counter for error from humidity sensor
bool lightStatus;     ///< status light relay
bool pumpStatus;      ///< status pump relay
int pumpTimer;        ///< counter for turn on reps
bool errLedStatus;    ///< status error led
char inChar;          ///< serial recived char

Output output;        ///< Outputs control methods

/**
 * @brief preparation to work, startup
 */
void setup()
{
  firstLoop = true;
  inChar = '0';
  error = 0;
  errCnt_ds18b20 = 0;
  errCnt_tank = 0;
  errCnt_light = 0;
  errCnt_hum = 0;
  lightStatus = false;
  pumpStatus = false;
  errLedStatus = false;

  delay(20);
  pinMode(BTN_LIGHT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_LIGHT_PIN ), LightInter, FALLING);
  
  while(!Serial);
  Serial.begin(9600);
}

/**
 * @brief main loop
 */
void loop()
{	
#ifdef DEBUG
  unsigned long start;
  start = millis(); 
#endif
  output.SetLight(lightStatus);
  output.SetPump(pumpStatus, pumpTimer);
  output.SetErrLed(errLedStatus);
  if (error == 0)
    {
      Measurement measurement(firstLoop);
      measurement.MeasurementTemp(averageTemp, errCnt_ds18b20);
      measurement.MeasurementTank(avarageTank, errCnt_tank);
      measurement.MeasurementLight(avarageLight, errCnt_light);
      measurement.MeasurementHum(avarageHum, errCnt_hum);
      SVR();
    }else{
    //lightStatus = false;
    //pumpStatus = false;
      errLedStatus =! errLedStatus;
      delay(100);
    }
  if (inChar != '0'){
    Reaction(inChar);
    inChar = '0';
  }
  firstLoop = false;
#ifdef DEBUG
  unsigned long mainTime = millis() - start; 
  Serial.print("inChar: ");
  Serial.println(inChar);
  Serial.print("Main time(ms): ");
  Serial.println(mainTime);  
  PrintMeasurements();
#endif  
  delay(2);
}

/**
 * @brief supervisor to control errors
 */
void SVR()
{
  if (errCnt_ds18b20 > maxErrCnt) error = 2;
  if (errCnt_tank > maxErrCnt) error = 3;
  if (errCnt_light > maxErrCnt) error = 4;
  if (errCnt_hum > maxErrCnt) error = 5;
}

/**
 * @brief light intrrupt 
 */
void LightInter()
{
  lightStatus = !lightStatus;
  delay(2);
}

/**
 * @brief serial interrupt
 */
void serialEvent() {
  char rec;
  char serialBuf[1]; 
  
  rec = Serial.readBytes(serialBuf, 1);
#ifdef DEBUG 
  Serial.println(serialBuf[0]);
#endif 

  inChar = serialBuf[0];
}

/**
 * @brief reactions for recived char from serial
 * @param data: recived char
 */
void Reaction(char data)
{
  ESPCom espcom;
  switch (data){
    case '1':  //reset
    {
      asm volatile ("  jmp 0");
    }
    break;
    case '2':  //send measurements
    {
      int convAvarageTemp = int(averageTemp * tempMultiplier);
      int mesaurements[7] = {convAvarageTemp, avarageTank, avarageLight, avarageHum, error, lightStatus, pumpStatus};
      espcom.SendMesureMsg(mesaurements,sizeof(mesaurements)/sizeof(int)); 
    }
    break;
    case '3':  //change light status
    {
      lightStatus = !lightStatus;
      espcom.SendResponsMsg(inChar);
    }
    break;
    case '4':  //change pump status
    {
      pumpStatus = true;
      pumpTimer = pumpOnTime;
      espcom.SendResponsMsg(inChar);
    }
    case '5':  //clear error
    {
      error = 0;
      espcom.SendResponsMsg(inChar);
    }
    break;
    default:
    break;
  }
}

/**
 * @brief print mesurments value via serial 
 */
void PrintMeasurements()
{
  Serial.print("Temp: ");
  Serial.print(averageTemp);
  Serial.print(" Tank: ");
  Serial.print(avarageTank);
  Serial.print(" Light: ");
  Serial.print(avarageLight);
  Serial.print(" Humidity: ");
  Serial.print(avarageHum);
  Serial.print(" error code: ");
  Serial.print(error);
  Serial.print(" light relay status: ");
  Serial.print(lightStatus);
  Serial.print(" pump relay status: ");
  Serial.print(pumpStatus);
  Serial.println();
}




