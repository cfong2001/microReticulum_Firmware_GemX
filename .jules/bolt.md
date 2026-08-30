
## Optimization: NRF52 EEPROM Access Optimization
- Replaced sequential 1-byte read loops of simulated EEPROM (Adafruit LittleFS) on NRF52 platforms with a dedicated `eeprom_read_block` utility.
- Discovered that each byte-read called `file.seek()` and `file.read()` which yielded poor results.
- Simulated performance showed roughly a 63x execution improvement when factoring in typical read-latency for LittleFS. Built successfully on ESP32 and RAK4631.
