#include "Arduino.h"
#include "ESPCom.h"

void ESPCom::SendResponsMsg(char data)
{
  Serial.println(data);
}

void ESPCom::SendMesureMsg(int* data, int len)
{
  Serial.print(len);
  for (int i=0; i<len; i++) {
    Serial.print(" ");
    Serial.print(data[i]);
  }
  Serial.print(CalcIntCRC8(data, len));
  Serial.println();
}

int ESPCom::CalcIntCRC8(int *data, int len)
{
  int crc = 0x00;
  while (len--) {
    int extract = *data++;
    for (int tempI = 8; tempI; tempI--) {
      int sum = (crc ^ extract) & 0x01;
      crc >>= 1;
      if (sum) {
        crc ^= 0x8C;
      }
      extract >>= 1;
    }
  }
  return crc;
}
