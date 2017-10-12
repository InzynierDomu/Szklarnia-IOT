/*
  GreenHouse IOT - Tests
  Create by Szymon Markiewicz
  http://www.inzynierdomu.pl/
 */

#ifndef Tests_h
#define Tests_h

class Tests
{
  public:
    bool DistanceMaxMin(int distance);
    bool DistanceToHighDifference(int distance, int &avarageValue);
    bool TempToHighDifference(float temp, float &avarageValue);
    bool LightToHighDifference(int light, int &avarageValue);
    bool HumToHighDifference(int humidity, int &avarageValue);
  private:
    const int maxDifferenceDistance = 20;
    const int maxDifferenceHum = 5;
	const int maxDifferenceTemp = 10;
    const int maxDifferenceLight = 10;
};

#endif

