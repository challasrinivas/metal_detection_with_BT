
#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
const int ir = 6;
const int metal=7;
const int motor1=2;
const int motor2=3;
const int motor3=4;
const int motor4=5;
String rdString="";

void setup() {
// put your setup code here, to run once:

pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(ir,INPUT);
pinMode(metal,INPUT);
Serial.begin(9600);

Serial.print("WELCOME TO THE PROJECT");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
         
    
if(digitalRead(ir) == LOW)
{
   lcd.clear();
   lcd.setCursor(0,0);
  Serial.println("CHECKING...");
  lcd.print("CHECKING...");
  delay(100);
  
  if(digitalRead(metal) == LOW)
  {
        Serial.println("METAL DETECTED");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("METAL DETECTED");
        delay(2000);
  }
  else
  {
    Serial.println("METAL NOT DETECTED");
    delay(1000);

/*------------ MOTOR PROGRAMMING ------------ */

digitalWrite(motor1,HIGH);
digitalWrite(motor2,LOW);
digitalWrite(motor3,HIGH);
digitalWrite(motor4,LOW);
Serial.println("Bottle Crushing Started");

delay(5000);

digitalWrite(motor1,LOW);
digitalWrite(motor2,LOW);
digitalWrite(motor3,LOW);
digitalWrite(motor4,LOW);
Serial.println("Bottle Crushing Stoped");
delay(2000);

/* END OF THE MOTOR */
   }
}
else
{
    Serial.println("INSERT PLASTIC");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("INSERT PLASTIC");
    delay(1000);
}
}

 
