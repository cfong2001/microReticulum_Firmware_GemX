## 2024-05-15 - Buffer Overflows from Sign Extension and Missing Null Terminators
**Vulnerability:** Several instances of `sprintf` into undersized buffers. Specifically, `char pin_char[6]` for a 6-digit PIN lacks space for the null terminator. Also, formatting `char` types with `%02X` can cause massive buffer overflows (e.g., `bt_devname[11]`) because negative `char` values are sign-extended to 32-bit integers, producing 8-character hex strings instead of 2.
**Learning:** In C/C++, `sprintf` will happily overwrite adjacent stack/heap memory if variables are larger than expected or if null terminators are forgotten. Sign extension is a silent killer for hex formatting of signed `char`.
**Prevention:** Always use `snprintf` instead of `sprintf`. Explicitly cast `char` to `uint8_t` when formatting as hex. Ensure `uint32_t` decimal string buffers are at least 11 bytes long, and always account for the null terminator.
## 2024-05-15 - Path Traversal in ESP32 SPIFFS WebServer
**Vulnerability:** The embedded ESP32 webserver in `Console.h` uses `SPIFFS.open(path)` directly with the user-supplied `server.uri()`. It does not sanitize directory traversal characters (`..`), allowing attackers to read arbitrary files from the filesystem.
**Learning:** Minimal embedded filesystems like SPIFFS or LittleFS do not automatically sandbox paths or evaluate `..` correctly to prevent escaping the webroot.
**Prevention:** Manually sanitize user-supplied paths by checking for and rejecting requests containing `..` before calling filesystem open APIs.
