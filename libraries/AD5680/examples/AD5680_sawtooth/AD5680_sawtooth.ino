//
//    FILE: AD5680_sawtooth.ino
//  AUTHOR: Rob Tillaart
// PUPROSE: test basic behaviour and performance


#include "AD5680.h"

AD5680 AD16_HW(8, &SPI);
AD5680 AD16_SW(5, 6, 7);

float frequency = 50;
float amplitude = 262144;  //  18 bits

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("AD5680_LIB_VERSION: ");
  Serial.println(AD5680_LIB_VERSION);

  AD16_HW.begin();
  AD16_SW.begin();

  Serial.print("HWSPI: ");
  Serial.println(AD16_HW.usesHWSPI());
  Serial.print("HWSPI: ");
  Serial.println(AD16_SW.usesHWSPI());
}


void loop()
{
  float period = 1000000.0 / frequency;
  float value = fmod(micros(), period);   //  0..period
  //  value = period - value;  //  reverse
  
  value = amplitude * value / period;
  AD16_HW.setValue(value);
  Serial.println(value);
}


//  -- END OF FILE --
