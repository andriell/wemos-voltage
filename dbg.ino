// debug

int dbgLvl = 1;

void dbgSetup() {
  Serial.println("To turn debug level send one of this command");
  Serial.println("dbg0 - turned off");
  Serial.println("dbg1 - general information");
  Serial.println("dbg2 - full information");
}

void dbgLoop() {
  String cmd = srCmd();
  if (cmd.startsWith(const_str_dbg)) {
    dbgLvl = cmd[3] - '0';
    Serial.print("Now debug level is ");
    Serial.println(dbgLvl);
  }
}

void dbg(int label, String message) {
  if (label <= dbgLvl) {
    Serial.print(message);
  }
}

void dbgLn(int label, String message) {
  if (label <= dbgLvl) {
    Serial.println(message);
  }
}

void dbg(int label, int message) {
  if (label <= dbgLvl) {
    Serial.print(message);
  }
}

void dbgLn(int label, int message) {
  if (label <= dbgLvl) {
    Serial.println(message);
  }
}

void dbg(int label, IPAddress message) {
  if (label <= dbgLvl) {
    Serial.println(message);
  }
}

void dbgLn(int label, IPAddress message) {
  if (label <= dbgLvl) {
    Serial.println(message);
  }
}
