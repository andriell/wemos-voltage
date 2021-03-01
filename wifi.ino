// Дожидается подключения к wi-fi
// Выводит лог на экран
void wifiConnection() {
  dbg(1, "Connecting to ");
  dbgLn(1, configWifiSsid);

  while (WiFi.status() != WL_CONNECTED) {
    ledBlink(1, 250);
    dbgLn(1, "Connecting to Wi-Fi");
  }
  dbgLn(1, "Wi-Fi connected");
  dbg(1, "IP address: ");
  dbgLn(1, wifiGetIpString());
  ledBlink(3, 500);
}

void wifiSetup() {
  dbg(1, "MAC: ");
  dbgLn(1, WiFi.macAddress());
  WiFi.hostname("Casket");
  WiFi.mode(WIFI_STA);
  WiFi.begin(configWifiSsid, configWifiPassword);

  wifiConnection();

  WiFi.setAutoReconnect(true);
}

String wifiGetIpString()
{
  const IPAddress ipAddress = WiFi.localIP();
  return String(ipAddress[0]) + String(".") + \
         String(ipAddress[1]) + String(".") + \
         String(ipAddress[2]) + String(".") + \
         String(ipAddress[3]);
}

void wifiLoop()
{
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    wifiConnection();
  }
}

// 5. High quality: 90% ~= -55db
// 4. Good quality: 75% ~= -65db
// 3. Medium quality: 50% ~= -75db
// 2. Low quality: 30% ~= -85db
// 1. Unusable quality: 8% ~= -96db
// 0. No signal
int wifiSignal() {
  long rssi = WiFi.RSSI();
  int r = 0;
  if (rssi > -55) {
    r = 5;
  } else if (rssi > -65) {
    r = 4;
  } else if (rssi > -75) {
    r = 3;
  } else if (rssi > -85) {
    r = 2;
  } else if (rssi > -96) {
    r = 1;
  }
  dbg(1, "RSSI: ");
  dbg(1, rssi);
  dbg(1, "db; lavel: ");
  dbgLn(1, r);
  return r;
}

void wifiDisconnect() {
  WiFi.disconnect();
}
