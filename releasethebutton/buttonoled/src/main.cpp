#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, /*scl=*/ 21, /*sda=*/ 22);
int button = 25;

void setup()
{
    pinMode(button, INPUT);
    u8g2.begin();
  	u8g2.enableUTF8Print();
    u8g2.setFont(u8g2_font_6x12_t_cyrillic);
}

void loop()
{
    if(digitalRead(button)==HIGH)
    {
      u8g2.setCursor(10, 15);
      u8g2.print("Release the button");
      u8g2.setCursor(50, 30);
      u8g2.print("BAKA!");
      u8g2.sendBuffer();
    }
    else
    {
      u8g2.clearBuffer();
    }
}
