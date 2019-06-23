#include <Arduino.h>
#include "sensors/flex.h"
#include "sensors/transceiver.h"


void setup() {
  Serial.begin(9600);
}

void loop() {
  int finger[5];
  readFlexPins(finger[0], finger[1], finger[2], finger[3], finger[4]);

  for(int i = 0; i < 5; i++){
    Serial.print(finger[i]);
    Serial.print(" | ");
  }

  Serial.println();
  delay(1000);
}
