#include <Arduino.h>
#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>

using namespace Adafruit_LittleFS_Namespace;
void setup() {
  File file(InternalFS);
}

void loop() {}
