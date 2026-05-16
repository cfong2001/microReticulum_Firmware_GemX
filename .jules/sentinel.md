## 2024-05-16 - Prevent Clickjacking and MIME-Sniffing in Web Console
**Vulnerability:** The embedded ESP32 web server in `Console.h` lacked essential HTTP security headers (`X-Content-Type-Options` and `X-Frame-Options`) when serving files via `server.streamFile()`.
**Learning:** In Arduino/ESP WebServer environments, security headers must be explicitly queued using `server.sendHeader()` *before* invoking `server.streamFile()`, as the streaming process initiates the HTTP response headers immediately.
**Prevention:** Always queue `X-Content-Type-Options: nosniff` and `X-Frame-Options: DENY` (or appropriate CSP directives) before any file streaming operations to prevent client-side interpretation vulnerabilities.
