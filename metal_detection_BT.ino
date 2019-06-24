//METAL DETECTOR PROGRAMMING USING ARDUINO

#include <SoftwareSerial.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  //RS=13,EN=12,D4=11,D5=10,D6=9,D7=8
SoftwareSerial blue(2,3);  // RX,TX PINS IN BLUETOOTH

const int ir = 6;
const int metal=7;
const int motor1=5;
String rdString="";

void setup() {
// put your setup code here, to run once:
blue.begin(9600); 
pinMode(motor1,OUTPUT);
pinMode(ir,INPUT);
pinMode(metal,OUTPUT);
Serial.begin(9600);

Serial.print("WELCOME TO");
Serial.println("PROJECT");

lcd.clear();
lcd.setCursor(0,0);
lcd.print(" WELCOME TO ");
lcd.setCursor(1,1);
lcd.println("PROJECT");
}

void loop() {
  // put your main code here, to run repeatedly:

 while(blue.available())  //  // Checking for serial communcation of bluetooth data
 {
      char pgmChar = (char)blue.read();  //getting data from the BT
      rdString += pgmChar;                //make a string of the characters coming on serial
    }
    blue.println("receiving data from the bluetooth");
    blue.println(rdString);
 
if(digitalRead(ir) == HIGH)
{
     lcd.clear();
     lcd.setCursor(0,0);
     Serial.println("ir working");
     lcd.print("ir working");
     delay(100);
  if(metal == HIGH)
  {
        digitalWrite(motor1,LOW);
        Serial.println("METAL DETECTED");
        blue.println("METAL DETECTED");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("METAL DETECTED");
        delay(1000);
  }
  else
  {
    digitalWrite(motor1,HIGH);
    delay(100);
    Serial.println("METAL NOT DETECTED");
    blue.println("METAL NOT DETECTED");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("METAL NOT DETECTED");
    delay(1000);
    // digitalWrite(motor1,LOW);
   }
  }
else
{
   Serial.println("INSERT PLASTIC");
   blue.println("INSERT PLASTIC");
   digitalWrite(motor1,LOW);
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,1);
   lcd.print("INSERT PLASTIC");
   delay(1000);
}
}


