#include <Arduino.h>
#include <EEPROM.h>

void setup() {
  uint8_t buf[10];
  EEPROM.readBytes(0, buf, 10);
  EEPROM.get(0, buf);
}
void loop() {}
