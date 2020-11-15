// Grove - Ultrasonic Ranger

#include "Ultrasonic.h"

Ultrasonic ultrasonic(0); //VCC to pin 0

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  long range = ultrasonic.MeasureInCentimeters();
  delay(10);
  Serial.print(range);
  Serial.println("cm");

}
