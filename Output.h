/*
  Smart garden - Output
  Create by Szymon Markiewicz
  http://www.inzynierdomu.pl/
 */

#ifndef Output_h
#define Output_h

class Output
{
  public:
    Output();
    void SetLight(bool state);
    void SetPump(bool state);
    void SetErrLed(bool state);
  private:
    void SetPinLvl(int pin, bool state);
};

#endif
