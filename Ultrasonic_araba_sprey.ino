#include <Servo.h>             //  Servo motor kütüphanesini ekledik

Servo myservo;                 // Kullanılacak servo ismi tanımladık

#define echoPin 12             //Ultrasonik sensörün echo pini Arduino'nun 12.pinine
#define trigPin 11             //Ultrasonik sensörün trig pini Arduino'nun 11.pinine tanımlandı.
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9              // Motor pinlerini tanımlıyoruz.
#define MotorL1 5
#define MotorL2 4
#define MotorLE 10


long sure, uzaklik;             //süre ve uzaklık diye iki çok uzun değişken tanımlıyoruz.
int  sayi=0;                    // sayı değişkeni tanımladık integer

void setup() {
  myservo.attach(3);            // servo motora bağlanacak çıkışı tanımadık 
  myservo.write(90);            // açılışta servo motorun açısı 90 dece ayarladık.

  pinMode(echoPin, INPUT);      // eko pini input tanımladık diğerli Output oldu
  pinMode(trigPin, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);      //Motorlarımızı çıkış olarak tanımlıyoruz.
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);


  Serial.begin(9600);            // Seri portu başlattık.

}

void loop() {

  digitalWrite(trigPin, LOW);    //sensör pasif hale getirildi
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);   //Sensore ses dalgasının üretmesi için emir verildi
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    //Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi

  sure = pulseIn(echoPin, HIGH); //ses dalgasının geri dönmesi için geçen sure ölçülüyor
  uzaklik = sure / 29.1 / 2;     //ölçülen süre uzaklığa çevriliyor

  Serial.println(uzaklik);

  if (uzaklik < 30){              // Uzaklık 30cm'den küçük ise sprey duruyor,  biraz geri ve sonra sağa dönüyor.
    geri();                       // Geri fonksiyonu çağrılyor.
    delay(500);
    sag();                        // sağa fonksiyonu çağrılyor.
    delay(800);
  }
  else {                         // Mesafe 30 CM büyükse ileri giderek spreyleme yapıyor.
    
    ileri();                     // ileri fonksiyonu çağrılyor.

    sayi++;                      // Spreyleme zamanı sayıyır.
    if (sayi>=500) {             // 500 den büyükse servoyu 0 derece yapıyor spreyliyor ve sayıyı sıfırlıyor.
    sayi=0; 
    myservo.write(0);           
    delay(500);  
    }else{
    myservo.write(90);         // değilse servo spreyleme pozisyonunu eski haline getiriyor.
    }
}
}



void ileri(){                  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, LOW);  // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRE, 255);   // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW);  // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 255);   // Sol motorun hızı 150
}


void sag(){                     // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH);  // Sağ motorun ileri hareketi pasif
  digitalWrite(MotorR2, LOW);   // Sağ motorun geri hareketi aktif
  analogWrite(MotorRE, 255);    // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH);  // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW);   // Sol motorun geri hareketi pasif
  analogWrite(MotorLE, 255);    // Sol motorun hızı 150
}


void geri(){                    // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
  digitalWrite(MotorR1, HIGH);  // Sağ motorun ileri hareketi pasif
  digitalWrite(MotorR2, LOW);   // Sağ motorun geri hareketi aktif
  analogWrite(MotorRE, 255);    // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW);   // Sol motorun ileri hareketi pasif
  digitalWrite(MotorL2, HIGH);  // Sol motorun geri hareketi aktif
  analogWrite(MotorLE, 255);    // Sol motorun hızı 150 
}
