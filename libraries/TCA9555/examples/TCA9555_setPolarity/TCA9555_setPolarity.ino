//
//    FILE: TCA9555_setPolarity.ino
//  AUTHOR: Rob Tillaart
// PUPROSE: test TCA9555 library
//     URL: https://github.com/RobTillaart/TCA9555


#include "Wire.h"
#include "TCA9555.h"


TCA9555 TCA(0x27);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("TCA9555_LIB_VERSION: ");
  Serial.println(TCA9555_LIB_VERSION);

  Wire.begin();
  TCA.begin();

  Serial.println("TEST digitalRead(pin)");
  for (int pin = 0; pin < 16; pin++)
  {
    int val = TCA.digitalRead(pin);
    Serial.print(val);
    Serial.print(' ');
  }
  Serial.println();

  Serial.println("\nchange polarity");
  Serial.println(TCA.getPolarity8(0));
  Serial.println(TCA.getPolarity8(1));  
  TCA.setPolarity8(0, 0xFF); // all inverted
  TCA.setPolarity8(1, 0xFF); // all inverted
  Serial.println(TCA.getPolarity8(0));
  Serial.println(TCA.getPolarity8(1));  

  Serial.println("\nafter setPolarity");
  for (int pin = 0; pin < 16; pin++)
  {
    int val = TCA.digitalRead(pin);
    Serial.print(val);
    Serial.print(' ');
  }
  Serial.println();
}


void loop()
{
}


//  -- END OF FILE --

