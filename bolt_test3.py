import os

with open("RNode_Firmware.ino", "r") as f:
    content = f.read()

# Replace on_receive_packet
content = content.replace("""void on_receive_packet(const RNS::Bytes& raw, const RNS::Interface& interface) {
#ifdef HAS_SDCARD
  TRACE("Logging receive packet to SD");
  String line = RNS::getTimeString() + String(" recv: ") + String(raw.toHex().c_str()) + "\\n";
	File file = SD.open("/tracefile.txt", FILE_APPEND);
	if (file) {
    file.write((uint8_t*)line.c_str(), line.length());
    file.close();
  }
	RNS::Packet packet({RNS::Type::NONE}, raw);
	if (packet.unpack()) {
    String line = RNS::getTimeString() + String(" recv: ") + String(packet.dumpString().c_str()) + "\\n";
    File file = SD.open("/tracedetails.txt", FILE_APPEND);
    if (file) {
      file.write((uint8_t*)line.c_str(), line.length());
      file.close();
    }
	}
#endif  // HAS_SDCARD
}""", """void on_receive_packet(const RNS::Bytes& raw, const RNS::Interface& interface) {
#ifdef HAS_SDCARD
  TRACE("Logging receive packet to SD");
  // ⚡ Bolt: Use sequential writes to avoid memory allocation and fragmentation from String concatenation
  File file = SD.open("/tracefile.txt", FILE_APPEND);
  if (file) {
    file.print(RNS::getTimeString());
    file.print(" recv: ");
    file.println(raw.toHex().c_str());
    file.close();
  }
  RNS::Packet packet({RNS::Type::NONE}, raw);
  if (packet.unpack()) {
    File details_file = SD.open("/tracedetails.txt", FILE_APPEND);
    if (details_file) {
      details_file.print(RNS::getTimeString());
      details_file.print(" recv: ");
      details_file.println(packet.dumpString().c_str());
      details_file.close();
    }
  }
#endif  // HAS_SDCARD
}""")

# Replace on_transmit_packet
content = content.replace("""void on_transmit_packet(const RNS::Bytes& raw, const RNS::Interface& interface) {
#ifdef HAS_SDCARD
  TRACE("Logging transmit packet to SD");
  String line = RNS::getTimeString() + String(" send: ") + String(raw.toHex().c_str()) + "\\n";
	File file = SD.open("/tracefile.txt", FILE_APPEND);
	if (file) {
    file.write((uint8_t*)line.c_str(), line.length());
    file.close();
  }
	RNS::Packet packet({RNS::Type::NONE}, raw);
	if (packet.unpack()) {
    String line = RNS::getTimeString() + String(" send: ") + String(packet.dumpString().c_str()) + "\\n";
    File file = SD.open("/tracedetails.txt", FILE_APPEND);
    if (file) {
      file.write((uint8_t*)line.c_str(), line.length());
      file.close();
    }
	}
#endif  // HAS_SDCARD
}""", """void on_transmit_packet(const RNS::Bytes& raw, const RNS::Interface& interface) {
#ifdef HAS_SDCARD
  TRACE("Logging transmit packet to SD");
  // ⚡ Bolt: Use sequential writes to avoid memory allocation and fragmentation from String concatenation
  File file = SD.open("/tracefile.txt", FILE_APPEND);
  if (file) {
    file.print(RNS::getTimeString());
    file.print(" send: ");
    file.println(raw.toHex().c_str());
    file.close();
  }
  RNS::Packet packet({RNS::Type::NONE}, raw);
  if (packet.unpack()) {
    File details_file = SD.open("/tracedetails.txt", FILE_APPEND);
    if (details_file) {
      details_file.print(RNS::getTimeString());
      details_file.print(" send: ");
      details_file.println(packet.dumpString().c_str());
      details_file.close();
    }
  }
#endif  // HAS_SDCARD
}""")

with open("RNode_Firmware.ino", "w") as f:
    f.write(content)
