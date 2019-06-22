#include <Arduino.h>

int readSerial()
{
  int i = Serial.parseInt();

  if(i < 1 || (i%1 != 0))
  {
    Serial.println("That isn't a valid integer");
    return 0;
  }
  Serial.println(i);
  Serial.parseInt();
  return i;
}

void findSide(int x, int y)
{
  float hypotenuse = sqrt(x*x + y*y);

  Serial.print("Hypotenuse = ");
  Serial.println(hypotenuse);
}

void calculate_hypotenuse(){
  int a;
  int b;
  float result;
  Serial.print("Enter a side value: ");
  while(!Serial.available());
  a = readSerial();
    if(a == 0)
    {
      return;
    }
  Serial.print("Enter the other side value: ");
  while(!Serial.available());
  b = readSerial();
    if(b == 0)
    {
      return;
    }
  findSide(a,b);

  Serial.println();
}
