// change speed of fan by writing into the Serial Window a value between 0 and 256.

#define channel 0 // led channel
#define controlPin 4

#define ledc_resolution 8 // 8 bit
#define ledc_frequency 5 // 5hz

float speed = 255; // max PWM signal -> max motor speed

void setup()
{
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");

  ledcSetup(channel, ledc_frequency, ledc_resolution); // frequency = 5000 hertz, resolution = 8 bit
  ledcAttachPin(controlPin, channel);
  ledcWrite(channel, speed);

}

void loop()
{

  String readString;

  while (Serial.available()) {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  if (readString.length() > 0) {
    speed = readString.toFloat();
    int maxFreq = pow(2, ledc_resolution);
    speed = constrain(speed, 0, maxFreq);  //min 0, max 256
    Serial.println((String)"Set speed: " + speed);
    ledcWrite(channel, speed);
    readString = "";
  }
}
