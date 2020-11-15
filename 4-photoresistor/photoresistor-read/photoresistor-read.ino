// read photo resistor
#define signalPin 4

void setup(){
 Serial.begin(9600);
 pinMode(signalPin, INPUT);// Set pResistor - A0 pin as an input (optional)
}

void loop(){
  int value = analogRead(signalPin);
  Serial.println(value);
}
