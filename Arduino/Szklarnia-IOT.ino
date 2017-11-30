/*
  GreenHouse IOT - Main
  Create by Szymon Markiewicz
  http://www.inzynierdomu.pl/
 */

#include "Measurement.h"
#include "Output.h"
#include "ESPCom.h"
#include "Pins.h"

//#define DEBUG

const int maxErrCnt = 5;
const int pumpOnTime = 10;
const int tempMultiplier = 100;

bool firstLoop;
float averageTemp;
int avarageTank;
int avarageLight;
int avarageHum;
int error;
int errCnt_ds18b20;
int errCnt_tank;
int errCnt_light;
int errCnt_hum;
bool lightStatus;
bool pumpStatus;
int pumpTimer;
bool errLedStatus;
char inChar;

Output output;

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

void SVR()
{
  if (errCnt_ds18b20 > maxErrCnt) error = 2;
  if (errCnt_tank > maxErrCnt) error = 3;
  if (errCnt_light > maxErrCnt) error = 4;
  if (errCnt_hum > maxErrCnt) error = 5;
}

void LightInter()
{
  lightStatus = !lightStatus;
  delay(2);
}

void serialEvent() {
  char rec;
  char serialBuf[1]; 
  
  rec = Serial.readBytes(serialBuf, 1);
  Serial.println(serialBuf[0]);

  inChar = serialBuf[0];
}

void Reaction(char data)
{
  ESPCom espcom;
  espcom.SendResponsMsg(inChar);
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
    }
    break;
    case '4':  //change pump status
    {
      pumpStatus = true;
      pumpTimer = pumpOnTime;
    }
    case '5':  //clear error
    {
      error = 0;
    }
    break;
    default:
    break;
  }
}

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




