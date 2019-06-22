#include <Arduino.h>
#include "testing_files/calc_hyp.h"

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  calculate_hypotenuse();
}
