// Serial.read
#define SR_LEN 64
char srCmdChr[SR_LEN];
String srCmdStr = const_str_empty;

void srLoop() {
  int i = 0;
  while (Serial.available()) {
    srCmdChr[i++] = Serial.read();
    if (i >= SR_LEN - 1) {
      break;
    }
  }
  srCmdChr[i] = '\0';
  if (i > 0) {
    srCmdStr = String(srCmdChr);
    Serial.println(srCmdStr);
  } else {
    srCmdStr = const_str_empty;
  }
}

String srCmd() {
  return srCmdStr;
}
