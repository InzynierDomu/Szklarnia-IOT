/**
 * @file ESPCom.cpp
 * @brief class to Arduino-ESP communication
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#include "Arduino.h"
#include "ESPCom.h"

/**
 * @brief send one char via serial port
 * @param data: char to send via serial port
 */
void ESPCom::SendResponsMsg(char data)
{
  Serial.println(data);
}

/**
 * @brief send avarage mesruments status and CRC via serial
 * @param data: array values to send
 * @param len: lenght of date array
 */
void ESPCom::SendMesureMsg(int* data, int len)
{
  Serial.print(len);
  for (int i=0; i<len; i++) {
    Serial.print(" ");
    Serial.print(data[i]);
  }
  Serial.print(" ");
  Serial.print(CalcIntCRC8(data, len));
  Serial.println();
}

/**
 * @brief  Calculate CRC8 checksum
 * @param  data: data to calculate crc
 * @param  len: lenght of date
 * @return CRC8 from date
 */
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
