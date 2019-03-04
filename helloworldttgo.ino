// Simple Hello World Example for TTGO T5 V2.0 ESP32 with 2.13" Waveshare display
// Based on example (PagedDisplayForSmallRam) from https://github.com/ZinggJM/GxEPD
// This dedicated version allow for (WAY) faster compile :-)

#include <GxEPD.h>
#include <GxGDE0213B1/GxGDE0213B1.h>      // 2.13" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include "Adafruit_GFX.h"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>


GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4



//#define DEMO_DELAY 3*60 // seconds
//#define DEMO_DELAY 1*60 // seconds
#define DEMO_DELAY 10

void setup(void)
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");
  display.init(9600); // enable diagnostic output on Serial
  Serial.println("setup done");
}

void loop()
{

  display.drawPaged(showFontCallback);
  delay(DEMO_DELAY * 1000);
}

void showFontCallback()
{
  const char* name = "FreeMonoBold9pt7b";
  const GFXfont* f = &FreeMonoBold9pt7b;
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println("Hello World...");

}
