## 2024-05-18 - LittleFS eeprom block reads optimization
**Learning:** The firmware on NRF52 simulates EEPROM using Adafruit LittleFS (InternalFileSystem). Single-byte reads (via `eeprom_read()`) incur high latency due to repeated `file.seek()`/`file.read()` calls.
**Action:** Use block reads (e.g., `file.read()`) for continuous data structures to maximize performance on the NRF52 platform.
