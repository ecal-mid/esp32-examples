//Grove - Electromagnet

#define VCC_PORT 0

void setup() {
  pinMode(VCC_PORT, OUTPUT);
}

void loop() {
  digitalWrite(VCC_PORT, HIGH);
  delay(1000);
  digitalWrite(VCC_PORT, LOW);
  delay(1000);
}
