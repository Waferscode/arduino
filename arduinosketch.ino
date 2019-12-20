#include <LCD.h>

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
//Heart beat pulse LCD
byte custom1[8] = {0b00000,0b00000,0b00011,0b00111,0b01111,0b01111,0b01111,0b01111};
byte custom2[8] = {0b00000,0b11000,0b11100,0b11110,0b11111,0b11111,0b11111,0b11111};
byte custom3[8] = {0b00000,0b00011,0b00111,0b01111,0b11111,0b11111,0b11111,0b11111};
byte custom4[8] = {0b00000,0b10000,0b11000,0b11100,0b11110,0b11110,0b11110,0b11110};
byte custom5[8] = {0b00111,0b00011,0b00001,0b00000,0b00000,0b00000,0b00000,0b00000};
byte custom6[8] = {0b11111,0b11111,0b11111,0b11111,0b01111,0b00111,0b00011,0b00001};
byte custom7[8] = {0b11111,0b11111,0b11111,0b11111,0b11110,0b11100,0b11000,0b10000};
byte custom8[8] = {0b11100,0b11000,0b10000,0b00000,0b00000,0b00000,0b00000,0b00000};
int temp = 100;
void setup() {
  {
  lcd.begin(16,2); 
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello world");
  lcd.createChar(1, custom1);
  lcd.createChar(2, custom2);
  lcd.createChar(3, custom3);
  lcd.createChar(4, custom4);
  lcd.createChar(5, custom5);

  lcd.setCursor(0, 0);
  lcd.createChar(6, custom6);
  lcd.createChar(7, custom7);
  lcd.createChar(8, custom8);
  delay(1500);
  lcd.clear();
   Serial.begin(9600); // Starting Serial Terminal
}

}
void loop () {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
//   lcd.print(inches);
//   lcd.print("in, ");
//   lcd.print(cm);
//   lcd.print("cm");
////  lcd.begin(16, 2);
  if(inches < 128) {
    temp = 8 * (inches); 
  }else
  temp = 1000;
   
   lcd.setCursor(6,0);
   lcd.write(byte(1));
   lcd.setCursor(7,0);
   lcd.write(byte(2));
   lcd.setCursor(8,0);
   lcd.write(byte(3));
   lcd.setCursor(9,0);
   lcd.write(byte(4));
   lcd.setCursor(6,1);
   lcd.write(byte(5));
   lcd.setCursor(7,1);
   lcd.write(byte(6));
   lcd.setCursor(8,1);
   lcd.write(byte(7));
   lcd.setCursor(9,1);
   lcd.write(byte(8));
   
   delay(1000);
   lcd.clear();
   lcd.print("Hey! beautiful!");
   
   for(int scrollright=0; scrollright<16; scrollright++){
    lcd.scrollDisplayRight();
    delay(temp / 5);
   }
  delay(temp);
   lcd.clear();
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
