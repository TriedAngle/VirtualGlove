#include <Arduino.h>
#include "sensors/flex.h"
#include "sensors/mpu.h""
#include "sensors/transceiver.h"

float finger[5];
float rotation[3];
float force[3];
const int BAUD_RATE = 9600;

void setup() {
  Serial.begin(BAUD_RATE);
  setupMPU();
}

void loop() {
  recordGyroRegisters();
  recordAccelRegisters();
  getGyroRotation(rotation[0], rotation[1], rotation[2]);
  getAccForce(force[0], force[1], force[2]);
  getAngles(finger[0], finger[1], finger[2], finger[3], finger[4]);
  float allData[10] = {rotation[0], rotation[1], rotation[2], force[0], force[1], force[2], finger[0], finger[1], finger[2], finger[3]};

  Serial.println(finger[1]);

  // Serial.println(String(finger[0]) + "|" + String(finger[1]) + "|"
  // + String(finger[2]) + "|" + String(finger[3]) + "|" + String(rotation[0]) + "|"
  // + String(rotation[1]) + "|" + String(rotation[2]) + "|" + String(force[0])+ "|"
  // + String(force[1]) + "|" + String(force[2]));

  //for(int i = 0; i < 5; i++){
  //  Serial.print(finger[i]);
  //  Serial.print(" | ");
  //}
  delay(50);
}
