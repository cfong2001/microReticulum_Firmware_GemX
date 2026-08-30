## 2024-06-25 - Python memory allocations during loop concatenations
**Learning:** In Python, string concatenation within a loop using the `+=` operator results in O(n^2) time complexity because Python strings are immutable and a new string is allocated for every concatenation. This is especially true for `build.py` script which repeatedly concatenates strings for generating HTML.
**Action:** Replace `md += "..."` loop constructs in Python with a list appending strategy (`md_parts.append("...")`) followed by a single `" ".join(md_parts)` to change time complexity to O(n) and reduce memory allocations.

## 2024-06-25 - C++ String Concatenation overhead inside loops
**Learning:** In Arduino `String` class, constructing and concatenating strings recursively, as seen in `on_log` function using `String line = RNS::getTimeString() + String(" [") + ...`, leads to excessive heap fragmentation and memory reallocation overhead per log call, which can eventually starve the memory on embedded targets.
**Action:** Replace `String` concatenation with sequential `Serial.print()` and `file.print()` statements to directly write data sequentially into the UART and SD stream without intermediate buffer allocations.

## 2024-06-25 - SPI Block transfers
**Learning:** For LoRa drivers (SX126x/SX128x), replacing byte loops with chunked block transfers `SPI.transfer(buffer, size)` significantly improves data throughput by reducing the transaction overhead per byte and allowing DMA optimization on supported platforms.
**Action:** Always prefer `SPI.transfer(buffer, size)` for copying multi-byte structures over SPI instead of manually iterating byte-by-byte. Ensure chunks fit within local stack memory constraints to prevent stack overflow.
