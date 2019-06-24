#include <Arduino.h>
#include "sensors/flex.h"
#include "sensors/mpu.h""
#include "sensors/transceiver.h"

int finger[5];
const int BAUD_RATE = 9600;

void setup() {
  Serial.begin(BAUD_RATE);
}

void loop() {
  readFlexPins(finger[0], finger[1], finger[2], finger[3], finger[4]);

  for(int i = 0; i < 5; i++){
    Serial.print(finger[i]);
    Serial.print(" | ");
  }

  Serial.println();
  delay(1000);
}
