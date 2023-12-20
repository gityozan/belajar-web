const int pinSensor = 11;
int motor1=9;
int motor2=8;

int hitung = 0;
int kondisi1 = 0;
int status1;
int jumlah,bacadata;

char n;
int bd;
String readString;
void setup()
{
  Serial.begin(9600);
  Serial.println("alat penghitung uang");
  delay(1000);
  Serial.println("ready...");
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  digitalWrite(8,1);
  digitalWrite(9,1);

  delay(500);
  digitalWrite(8,0);
    digitalWrite(9,0);

}


// ------ program utama looping/berulang terus-menerus ------ //
void loop()
{
  
if (Serial.available())
{
  bacadata=Serial.parseInt();
 Serial.print("Jumlah uang : ");
 Serial.println(hitung);
 Serial.print("Jumlah : ");
 Serial.println(bacadata);
}
  

   if (hitung < bacadata) //jika belum 6 lembar motor akan hidup
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  sensor();
}
else //jika udah 6 lembar maka motor mati
{
  delay (1000);
  digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);


} 
  
if (bacadata ==99) 
{
 
 // jumlah uang kembali menjadi = 0
 hitung = 0;
 bacadata = 0;
 Serial.print("Jumlah uang : ");
 Serial.println(hitung);
 Serial.print("keinginan : ");
 Serial.println(bacadata);
 }

 // jika tombol reser tidak ditekan
 else
 {
 // jumlah barang tetap
 hitung = hitung;
 bacadata=bacadata;
 }
 delay(50);
}

void sensor(){
  hitung = constrain(hitung, 0, 100); // ==> Jumlah maks barang

 status1 = digitalRead(pinSensor);

 if (status1 == HIGH)
 {
 hitung = hitung;
 kondisi1 = 0;
 }
 else if (status1 == LOW && kondisi1 == 0)
 {
 // jumlah barang bertambah 1
 hitung += 1;
 // kondisi1 menjadi bernilai = 1
 kondisi1 = 1;
 
 }

 // jika pin sensor bernilai LOW dan kondisi bernilai = 1
 else if (status1 == LOW && kondisi1 == 1)
 {
 // hasil hitung tetap
 hitung = hitung;
 // kondisi1 tetap bernilai =1
 kondisi1 = 1;
 }

 
 Serial.print("Jumlah uang : ");
 Serial.println(hitung);
 Serial.print("Keinginan : ");
 Serial.println(bacadata);
}
