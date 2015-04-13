/*
    NASA Space Apps Challenge 2015
     > Title:     Sensor Yourself
     > Team:      ProSense
     > Location:  Tirana, Albania
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

const int TRIG = 8;
const int ECHO = 7;
const int BUZZ = 5;
 
void setup(){
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  for(int i = 0; i< 3; i++)
  {
	lcd.backlight();
	delay(250);
	lcd.noBacklight();
	delay(250);
  }
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("***** ProSense *****");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("V 1.0");
  delay(1500);  
  
  lcd.clear();
  lcd.setCursor(0,0);
  delay (1000);
  lcd.print("NASA Space Apps ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Challenge 2015");
  delay(1000); 
}
 
void loop(){
  
  long duration, cm;
  //long inches;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
   
  duration = pulseIn(ECHO, HIGH);
  //inches = duration / 74 / 2 ;
  cm = duration / 29 / 2 ;
   
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distanca nga objekti");
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print(" cm");
  
  if(cm <= 20)
  {
	analogWrite(BUZZ, (20 - cm) * 10);
        lcd.clear();
        lcd.setCursor(0,3);
        lcd.print("                           RREZIK!");
  }
  else
  {
	digitalWrite(BUZZ, LOW);
  }
   
  delay(100);
  pinMode(ECHO, INPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
}


