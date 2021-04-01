int led = 4;
void setup(){
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int potDeger = analogRead(A0);
  int yeniDeger = map(potDeger, 0,1023,0,255);
  if(yeniDeger>=100){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
    delay(1000);
  }
  Serial.println(yeniDeger);
}
