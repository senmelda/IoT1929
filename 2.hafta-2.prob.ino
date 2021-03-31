
#define BLYNK_PRINT DebugSerial


// You could use a spare Hardware Serial on boards that have it (like Mega)
//#include <SoftwareSerial.h>
//SoftwareSerial DebugSerial(2, 3); // RX, TX


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

#define BLYNK_PRINT Serial
//#include <ESP8266WiFi.h>
#include <BlynkSimpleStream.h>

#include <Servo.h>
Servo servo;


char auth[] = "L9pcsyBXvk4q3wWkhZMNEs2BokSNWtoK";



void setup()
{
  servo.attach(4);
  // Servo Nodemcu üzerinde D2 pinine bağlanacaktır.
}

void loop()
{
  Blynk.run();
}
