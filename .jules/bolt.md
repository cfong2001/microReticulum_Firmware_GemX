## 2024-04-25 - [Optimize SPI read operations]
**Learning:** For SPI block transfers, specifically in `readBuffer` implementations in LoRa drivers (`sx126x.cpp`, `sx128x.cpp`), `SPI.transfer(buffer, size)` requires DMA and significantly lowers overhead compared to a `for` loop `SPI.transfer(0x00)` for each byte. We must `memset(buffer, 0x00, size)` before calling the block transfer because it simultaneously sends and receives.
**Action:** Replace byte-level SPI transfers for buffer reads with `memset` and block `SPI.transfer`.
