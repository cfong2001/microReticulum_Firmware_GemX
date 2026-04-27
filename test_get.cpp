#include <Arduino.h>
#include <EEPROM.h>

void setup() {
  uint8_t dev_sig[64];
  EEPROM.get(0, dev_sig);
}

void loop() {}
