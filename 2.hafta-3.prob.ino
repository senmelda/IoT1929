#include<Servo.h>
int potPin = A0;
int potPin2 = A1;
Servo servoM;
Servo servoM2;
int pos = 0;
int pos2 = 0;

void setup() {
servoM.attach(9);
servoM2.attach(6);
}

void loop() {
pos = analogRead(potPin);
pos = map(pos, 0, 1023, 0, 180);
servoM.write(pos);
pos2 = analogRead(potPin2);
pos2 = map(pos2, 0, 1023, 0, 180);
servoM2.write(pos2);
delay(15);
}
