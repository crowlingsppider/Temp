#include <Servo.h>

Servo myservo;  // Create servo object to control a servo
int irSensor = 2;  // IR sensor input pin
int buzzer = 8;    // Buzzer output pin
int pos = 0;       // Variable to store servo position

void setup() {
  myservo.attach(9);   // Attaches the servo on pin 9 to the servo object
  pinMode(irSensor, INPUT);  // IR sensor as input
  pinMode(buzzer, OUTPUT);   // Buzzer as output
}

void loop() {
  int sensorValue = digitalRead(irSensor);  // Read IR sensor value

  if (sensorValue == HIGH) {  // If object detected
    myservo.write(90);    // Turn servo to 90 degrees
    digitalWrite(buzzer, HIGH);  // Turn on buzzer
  } else {  // If no object detected
    myservo.write(0);     // Turn servo back to 0 degrees
    digitalWrite(buzzer, LOW);   // Turn off buzzer
  }

  delay(200);  // Short delay to avoid jitter
}
