#include <Arduino.h>

const int flex_pins[5] = {A0, A1, A2, A3, A4};

void readFlexPins(float& f1, float& f2, float& f3, float& f4, float& f5){
  f1 = analogRead(flex_pins[0]);
  f2 = analogRead(flex_pins[1]);
  f3 = analogRead(flex_pins[2]);
  f4 = analogRead(flex_pins[3]);
  f5 = analogRead(flex_pins[4]);
}

void getAngles(float& f1, float& f2, float& f3, float& f4, float& f5){
  const float VCC = 4.725; // Measured voltage of Ardunio 5V line
  const float R_DIV = 10000.0; // Measured resistance of 3.3k resistor

  // Upload the code, then try to adjust these values to more
  // accurately calculate bend degree.
  const float STRAIGHT_RESISTANCE0 = 40300.0; // resistance when straight
  const float BEND_RESISTANCE0 = 96000.0; // resistance at 90 deg

  const float STRAIGHT_RESISTANCE1 = 32300.0; // resistance when straight
  const float BEND_RESISTANCE1 = 90000.0; // resistance at 90 deg

  const float STRAIGHT_RESISTANCE2 = 42300.0; // resistance when straight
  const float BEND_RESISTANCE2 = 93000.0; // resistance at 90 deg

  const float STRAIGHT_RESISTANCE3 = 32300.0; // resistance when straight
  const float BEND_RESISTANCE3 = 85000.0; // resistance at 90 deg

  const float STRAIGHT_RESISTANCE4 = 37300.0; // resistance when straight
  const float BEND_RESISTANCE4 = 90000.0; // resistance at 90 deg

  float flexV[5];
  flexV[0] = analogRead(flex_pins[0]) * VCC / 1023.0;
  flexV[1] = analogRead(flex_pins[1]) * VCC / 1023.0;
  flexV[2] = analogRead(flex_pins[2]) * VCC / 1023.0;
  flexV[3] = analogRead(flex_pins[3]) * VCC / 1023.0;
  flexV[4] = analogRead(flex_pins[4]) * VCC / 1023.0;

  float flexR[5];
  flexR[0] = R_DIV * (VCC / flexV[0] - 1.0);
  flexR[1] = R_DIV * (VCC / flexV[1] - 1.0);
  flexR[2] = R_DIV * (VCC / flexV[2] - 1.0);
  flexR[3] = R_DIV * (VCC / flexV[3] - 1.0);
  flexR[4] = R_DIV * (VCC / flexV[4] - 1.0);

  float angle[5];
  angle[0] = map(flexR[0], STRAIGHT_RESISTANCE0, BEND_RESISTANCE0, 0, 90.0);
  angle[1] = map(flexR[1], STRAIGHT_RESISTANCE1, BEND_RESISTANCE1, 0, 90.0);
  angle[2] = map(flexR[2], STRAIGHT_RESISTANCE2, BEND_RESISTANCE2, 0, 90.0);
  angle[3] = map(flexR[3], STRAIGHT_RESISTANCE3, BEND_RESISTANCE3, 0, 90.0);
  angle[4] = map(flexR[4], STRAIGHT_RESISTANCE4, BEND_RESISTANCE4, 0, 90.0);

  f1 = angle[0];
  f2 = angle[1];
  f3 = angle[2];
  f4 = angle[3];
  f5 = angle[4];
}
