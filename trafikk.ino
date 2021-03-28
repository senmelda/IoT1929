int kirmiziled = 10; // kırmızı ledi Arduino uno da 10 nolu pinimize atadık
int sariled = 11; // sarı ledi Arduino uno da 11 nolu pinimize atadık
int yesilled = 12; // yeşil ledi Arduino uno da 12 nolu pinimize atadık
void setup() {
 
pinMode(kirmiziled, OUTPUT);
pinMode(sariled, OUTPUT); 
pinMode(yesilled, OUTPUT); 
 
}
 
void loop() {
 
digitalWrite(kirmiziled, HIGH); 
delay(10000); 
digitalWrite(sariled, HIGH); 
delay(10000); 
digitalWrite(kirmiziled, LOW); 
digitalWrite(sariled, LOW); 
digitalWrite(yesilled, HIGH);
delay(2000); 
digitalWrite(sariled, HIGH);
delay(5000); 
digitalWrite(yesilled, LOW); 
digitalWrite(sariled, LOW); 
}
