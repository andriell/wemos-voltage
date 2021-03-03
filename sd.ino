// GND  - GND
// VCC  - VCC
// MISO - D6
// MOSI - D7
// SCK  - D5
// CS   - D8



void sdSetup() {
  // контакт, подключенный к CS-линии SD-карты
  if (!SD.begin(WEMOS_D8)) {
    dbgLn(1, "SD card failed, or not present");
    while (1) {
      ledOn();
      delay(100);
      ledOff();
      delay(100);
    }
  }
  dbgLn(1, "SD card initialized.");
}

String sdNextFileName(String fName, String ext) {
  String r;
  for (int i = 1; i < 512; i++) {
    r = "" + fName + i + ext;
    // Check to see if the file exists:
    if (SD.exists(r)) {
      dbg(2, "SD file: ");
      dbg(2, r);
      dbgLn(2, " exists.");
    } else {
      dbg(1, "SD file: ");
      dbg(1, r);
      dbgLn(1, " doesn't exist.");
      break;
    }
  }
  return r;
}
