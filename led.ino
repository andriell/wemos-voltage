void ledSetup() {
  pinMode(WEMOS_D4_LED, OUTPUT);  // initialize onboard LED as output
  delay(10);
}

void ledBlink(int n, unsigned long d) {
  for (int i = 0; i <= n; i++) {
    digitalWrite(WEMOS_D4_LED, LOW);
    delay(d);
    digitalWrite(WEMOS_D4_LED, HIGH);
    delay(d);
  }
}

void ledOn() {
  digitalWrite(WEMOS_D4_LED, LOW);
}

void ledOff() {
  digitalWrite(WEMOS_D4_LED, HIGH);
}
