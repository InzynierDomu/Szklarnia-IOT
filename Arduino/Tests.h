/**
 * @file Tests.h
 * @brief class with tests sensors for bad measurments
 * @author by Szymon Markiewicz
 * @details http://www.inzynierdomu.pl/  
 * @date 04-2017
 */

#ifndef Tests_h
#define Tests_h

/**
 * @brief tests sensors for bad measurments
 */
class Tests
{
  public:
    bool DistanceMaxMin(int distance);                          ///< check tank liquid sensor for min/max measurement
    bool DistanceToHighDiff(int distance, int &avarageValue);   ///< check tank liquid sensor for max difference
    bool TempToHighDiff(float temp, float &avarageValue);       ///< check thermometer for max difference
    bool LightToHighDiff(int light, int &avarageValue);         ///< check light sensor for max difference
    bool HumToHighDiff(int humidity, int &avarageValue);        ///< check humidity sensor for max difference
  private:
    const int maxDiffDistance = 20;       ///< max difference for tank liquid sensor measurements
    const int maxDiffHum = 5;             ///< max difference for air humidity sensor measurements
    const int maxDiffTemp = 10;           ///< max difference for thermometer
    const int maxDiffLight = 10;          ///< max difference for light sensor
    const int minDistancePercent = 0;     ///< min tank liquid sensor measurement
    const int maxDistancePercent =100;    ///< max tank liquid sensor measurement
};

#endif

