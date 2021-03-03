// SCK - D1
// SDA - D2

SH1106 display(0x3C, WEMOS_D1, WEMOS_D2);

void displaySetup() {
  display.init();
  display.flipScreenVertically();
  displayLog(String("Loading..."));
}

void displayLoop() {
  display.clear();
  
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, timeString());

  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 10, "ROW: " + String(liionRaw()));

  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 34, "V: " + String(liionV()));
  display.display();
}


int displayLogPosition = 0;

// Вывод строчки лога на экран
void displayLog(String s) {
  Serial.println(s);
  if (displayLogPosition > 5) {
    displayLogPosition = 0;
    display.clear();
  }
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, displayLogPosition * 10, s);
  displayLogPosition++;

  display.display();
}
