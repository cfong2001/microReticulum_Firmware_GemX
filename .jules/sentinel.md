## 2024-05-01 - [CRITICAL] Buffer Overflow Vulnerabilities

**Vulnerability/Learning:**
The application used `sprintf` for string formatting, leading to multiple buffer overflow vulnerabilities.
1. In `Bluetooth.h`, a `char` array `bt_dh` was printed as hexadecimal using `%02X`. Because `char` is signed, values > 127 get sign-extended (e.g., `0xFFFFFF80`), expanding the format from 2 characters to 8 characters and overflowing the 11-byte stack buffer `bt_devname`.
2. In `Bluetooth.h`, a `uint32_t` representing a PIN code was formatted into `char pin_char[6]`. A `uint32_t` can hold up to 10 decimal digits, which plus a null terminator requires an 11-byte buffer minimum. The `[6]` size was actively overflowing even with 6-digit pins.

**Prevention:**
1. Always use `snprintf` with a defined bounding size instead of `sprintf`.
2. When formatting numeric variables to strings, use properly sized buffers. (e.g., 12 bytes minimum for `uint32_t`).
3. Explicitly cast `char` variables to `uint8_t` when formatting them as hex to prevent implicit integer sign-extension.
