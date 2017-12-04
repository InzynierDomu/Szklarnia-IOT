/**
 * @file Output.h
 * @brief class with handler mapping outputs
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#ifndef Output_h
#define Output_h

/**
 * @brief handler mapping outputs
 */
class Output
{
  public:
    Output();                                 ///< constructor
    void SetLight(bool state);                ///< set light relay state
    void SetPump(bool &state, int &timer);    ///< set pump relay state
    void SetErrLed(bool state);               ///< set error led state
  private:
    void SetPinLvl(int pin, bool state);      ///< set output pin state
};

#endif
