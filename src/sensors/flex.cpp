#include <Arduino.h>

const int flex_pins[5] = {A0, A1, A2, A3, A4};

void readFlexPins(int& f1, int& f2, int& f3, int& f4, int& f5){
  f1 = analogRead(flex_pins[0]);
  f2 = analogRead(flex_pins[1]);
  f3 = analogRead(flex_pins[2]);
  f4 = analogRead(flex_pins[3]);
  f5 = analogRead(flex_pins[4]);
}
