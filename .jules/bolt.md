## 2024-05-12 - Prevent SPI byte-by-byte looping and dynamic String logging

**Learning:** Microcontrollers executing Arduino code are susceptible to significant performance degradation when constructing dynamic `String` objects (e.g. `String line = ... + ...`) inside high-frequency packet callbacks (`on_receive_packet`, `on_transmit_packet`) due to continuous heap allocation and memory fragmentation. Additionally, executing SPI transfers byte-by-byte inside a `for` loop prevents the underlying HAL from utilizing DMA or hardware FIFOs.

**Action:** Replace `String` concatenation in logging routines with sequential `file.print()` or `Serial.print()` statements. In SPI peripheral driver code, identify byte-level transfers and replace them with block transfers (`SPI.transfer(buffer, size)`), chunking large non-destructive writes and utilizing `memset` to pre-fill buffers for clean reads. Ensure Python testing scripts used to make these changes are deleted before submitting code.
