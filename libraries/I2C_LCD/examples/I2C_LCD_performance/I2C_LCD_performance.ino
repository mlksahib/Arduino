//    FILE: I2C_LCD_performance.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: per I2C_LCD library
//     URL: https://github.com/RobTillaart/I2C_LCD


#include "Arduino.h"
#include "Wire.h"

#include "I2C_LCD.h"


#define BACKLIGHT_PIN   3
#define En_pin          2
#define Rw_pin          1
#define Rs_pin          0
#define D4_pin          4
#define D5_pin          5
#define D6_pin          6
#define D7_pin          7


I2C_LCD lcd(39);

void performance(uint32_t speed)
{
  Serial.println(__FUNCTION__);
  Serial.print("speed:\t");
  Serial.println(speed);
  delay(100);

  Wire.setClock(speed);
  lcd.setCursor(3, 3);

  uint32_t start = micros();
  lcd.print(__TIME__);
  uint32_t stop = micros();

  Serial.print("time (us): ");
  Serial.println(stop - start);
  Serial.println();
  delay(100);
}


void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println(__FILE__);
  Serial.print("I2C_LCD_LIB_VERSION: ");
  Serial.println(I2C_LCD_LIB_VERSION);
  Serial.println();

  lcd.config(39, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin, BACKLIGHT_PIN);

  Wire.begin();
  Wire.setClock(400000);
  lcd.begin(20, 4);

  lcd.display();
  delay(1000);
  lcd.noDisplay();
  delay(1000);
  lcd.display();

  lcd.clear();

  for (uint32_t speed = 100000; speed <= 800000; speed += 100000)
  {
    performance(speed);
  }
  Wire.setClock(100000);
}


void loop()
{
  lcd.home();
  lcd.print(millis());
  delay(1000);
}


//  -- END OF FILE --
