/*
  GreenHouse IOT - ESPCom
  Create by Szymon Markiewicz
  http://www.inzynierdomu.pl/
 */

#ifndef ESPCom_h
#define ESPCom_h

#include "Arduino.h"

class ESPCom
{
  public:
    void SendResponsMsg(char data);
    void SendMesureMsg(int* data, int len);
  private:
    int CalcIntCRC8(int *data, int len);
};

#endif
