## 2026-05-18 - Prevent String Object Heap Fragmentation in High-Frequency C++ Callbacks
**Learning:** In Arduino/C++ environments, returning dynamic `String` objects or heavily using `String` concatenation in high-frequency callbacks (like logging or packet events) causes excessive heap fragmentation and overhead.
**Action:** Optimize by passing strings by `const String&`, returning string literals as `const char*`, and replacing concatenation operations with sequential `stream.print()` statements directly to the target buffer or file.
