#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "const.h"
#include <SPI.h>
#include <SD.h>

// Time Timekeeping functionality for Arduino
#include <TimeLib.h>
// ESP8266 and ESP32 OLED driver for SSD1306 displays
#include<SH1106.h>


#define WEMOS_A0     17
#define WEMOS_D0     16
#define WEMOS_D1     5
#define WEMOS_D2     4
#define WEMOS_D3     0
#define WEMOS_D4_LED 2
#define WEMOS_D5     14
#define WEMOS_D6     12
#define WEMOS_D7     13
#define WEMOS_D8     15
#define WEMOS_TX     1
#define WEMOS_RX     3

#define MAX_UL     0xFFFFFFFFUL

String fileName;

void setup() {
  wemosSetup();
  dbgSetup();
  ledSetup();
  displaySetup();
  sdSetup();
  fileName = sdNextFileName("liion_", ".csv");
  wifiSetup();
  timeSetup();
  displayLog(timeString());
}

unsigned long mainMillis() {
  return  millis() + (MAX_UL - 30000UL);
}

void loop() {
  unsigned long startMillis = mainMillis();
  displayLoop();

  String dataString = "" + timeHMSString() + "\t" + liionRaw();
  File dataFile = SD.open(fileName, FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    ledBlink(3, 500);
    dbgLn(1, dataString);
  } else {
    dbg(1, "error opening ");
    dbgLn(1, fileName);
  }

  

  unsigned long endMillis = mainMillis();
  unsigned long executionTime;
  if (endMillis < startMillis) {
    executionTime = MAX_UL - startMillis;
    executionTime += endMillis + 1;
  } else {
    executionTime = endMillis - startMillis;
  }

  if (executionTime < 60000UL) {
    delay(60000UL - executionTime);
  }
}
