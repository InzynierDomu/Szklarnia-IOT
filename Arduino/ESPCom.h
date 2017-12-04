/**
 * @file ESPCom.h
 * @brief class to Arduino-ESP communication
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#ifndef ESPCom_h
#define ESPCom_h

#include "Arduino.h"

/**
 * @brief Arduino-ESP communication
 */
class ESPCom
{
  public:
    void SendResponsMsg(char data);           ///< send one char via serial port
    void SendMesureMsg(int* data, int len);   ///< send avarage mesruments status and CRC via serial
  private:
    int CalcIntCRC8(int *data, int len);      ///< Calculate CRC8 checksum
};

#endif
