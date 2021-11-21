/*
  "countdown" from green to red led using distance from ultrasonic sensor

  Wiring:
    Ultrasonic sensor
      VCC to 5v
      Trig to 7
      Echo to 6
      Gnd to ground
    Leds
      Red positive to 10 with 330 ohm res
      Orange positive to 9 with 330 ohm res
      Yellow positive to 5 with 330 ohm res
      Green positive to 3 with 220 ohm res
      All leds ground together to arduino ground
*/



const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const int redLed = 10;
const int orangeLed = 9;
const int yellowLed = 5;
const int greenLed = 3;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(redLed, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.println();
   updateLed(inches);
   delay(200);
}

void updateLed(int inches) {
  if(inches < 2) {
    analogWrite(greenLed, 0);
    analogWrite(yellowLed, 0);
    analogWrite(orangeLed, 0);
    
    // flashes red
    analogWrite(redLed, 150);
    delay(100); // delay here is half update delay
    analogWrite(redLed, 0);
  }
  else if(inches < 5) {
    analogWrite(greenLed, 0);
    analogWrite(yellowLed, 0);
    analogWrite(orangeLed, 0);
    analogWrite(redLed, 150);
  }
  else if(inches < 10) {
    analogWrite(greenLed, 0);
    analogWrite(yellowLed, 0);
    analogWrite(orangeLed, 150);
    analogWrite(redLed, 150);
  }
  else if(inches < 20) {
    analogWrite(greenLed, 0);
    analogWrite(yellowLed, 150);
    analogWrite(orangeLed, 150);
    analogWrite(redLed, 150);
  }
  else if(inches >= 20) {
    analogWrite(greenLed, 150);
    analogWrite(yellowLed, 150);
    analogWrite(orangeLed, 150);
    analogWrite(redLed, 150);
  }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
