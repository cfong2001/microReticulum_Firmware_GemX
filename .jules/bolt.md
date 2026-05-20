## 2024-05-18 - [Avoid String allocations]
**Learning:** Arduino `String` allocations, particularly in heavily used paths like web server responses or debug logging, cause unnecessary memory allocations and fragmentation. Function parameters should use `const String&` instead of `String`, and functions returning string literals should return `const char*`.
**Action:** Always prefer `const String&` for input arguments when passing objects, and `const char*` for returning string literals or when passing inline literal strings as arguments.
