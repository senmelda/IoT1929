 /*Açıklama: Arduino'nun 13,12,11 ve 10.pinlerine bağlı olan LEDleri
             sağdan sola ve soldan sağa belirlenen zaman aralığında yakıp söndürmek.
 */
int i,j,k;
void setup() //Uygulama içinde tek seferlik işlemlerin yapılacağı bölüm.
{
  for(i=10; i<=13; i++) //i değişkeni 10'dan başlayıp 13'e kadar 1'er 1'er arttırılır.
  {
    pinMode(i,OUTPUT); //"for döngüsü" kullanılarak pinler OUTPUT olarak ayarlandı.
  }
}
void loop() //Uygulama içinde sürekli yapılması istenen işlemlerin yapılacağı bölüm.
{
  for(j=13; j>=10; j--) //j değişkeni 13'tan başlayıp 10'a kadar 1'er 1'er azaltılır.
  {//LEDler soldan sağa(13.pinden 10.pine doğru) yakılıp söndürülür.
    digitalWrite(j,HIGH); 
    delay(50); 
    digitalWrite(j,LOW);
    delay(50);
  }
  for(k=10; k<=13; k++) //k değişkeni 10'dan başlayıp 13'e kadar 1'er 1'er arttırılır.
  {//LEDler sağdan sola(10.pinden 13.pine doğru) yakılıp söndürülür.
    digitalWrite(k,HIGH); 
    delay(50); 
    digitalWrite(k,LOW); 
    delay(50);
  }
}
