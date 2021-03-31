#include<Servo.h>
Servo motor;
int aci;
void setup()
{
  motor.attach(3);
}

void loop()
{
  for(int i=0;i<=180;i=i+15){
    motor.write(i);
    delay(1000);
  }
  for(int j=180;j>=0;j=j-30){
    motor.write(j);
    delay(1000);
  }
}
