#include <LiquidCrystal_I2C.h> //library required for liquid crystal display
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// push button 
int go=7;
int count=0;
//Analog input from the the sensor circuit 
int dataout=A0;
unsigned long temp=0;
//Heart beat pulse LCD
byte custom1[8] = {0b00000,0b00000,0b00011,0b00111,0b01111,0b01111,0b01111,0b01111};
byte custom2[8] = {0b00000,0b11000,0b11100,0b11110,0b11111,0b11111,0b11111,0b11111};
byte custom3[8] = {0b00000,0b00011,0b00111,0b01111,0b11111,0b11111,0b11111,0b11111};
byte custom4[8] = {0b00000,0b10000,0b11000,0b11100,0b11110,0b11110,0b11110,0b11110};
byte custom5[8] = {0b00111,0b00011,0b00001,0b00000,0b00000,0b00000,0b00000,0b00000};
byte custom6[8] = {0b11111,0b11111,0b11111,0b11111,0b01111,0b00111,0b00011,0b00001};
byte custom7[8] = {0b11111,0b11111,0b11111,0b11111,0b11110,0b11100,0b11000,0b10000};
byte custom8[8] = {0b11100,0b11000,0b10000,0b00000,0b00000,0b00000,0b00000,0b00000};
void setup() 
{
lcd.begin(16, 2);
lcd.createChar(1, custom1);
lcd.createChar(2, custom2);
lcd.createChar(3, custom3);
lcd.createChar(4, custom4);
lcd.createChar(5, custom5);
{
 lcd.setCursor(0, 0);
lcd.createChar(6, custom6);
lcd.createChar(7, custom7);
lcd.createChar(8, custom8);

pinMode(dataout,INPUT);
pinMode(go,INPUT_PULLUP);
}

void loop() 
//Displays Instructions for using sensor on display
 lcd.print("Place A Finger");
 lcd.setCursor(0, 1);
 lcd.print("Then Press Start");
 
  while(digitalRead(start)>0);
  
   lcd.clear();
   temp=millis();
   
   while(millis()<(temp+10000))
   {
      if(analogRead(dataout<100)
        {
         count=count+1;
         
         lcd.setCursor(6, 0);
         lcd.write(byte(1));
         lcd.setCursor(7, 0);
         lcd.write(byte(2));
         lcd.setCursor(8, 0);
         lcd.write(byte(3));
         lcd.setCursor(9, 0);
         lcd.write(byte(4));

         lcd.setCursor(6, 1);
         lcd.write(byte(5));
         lcd.setCursor(7, 1);
         lcd.write(byte(6));
         lcd.setCursor(8, 1);
         lcd.write(byte(7));
         lcd.setCursor(9, 1);
         lcd.write(byte(8));
         
         while(analogRead(dataout)<100);

         lcd.clear();
        }
   }
   
         lcd.clear();
         lcd.setCursor(0, 0);
         count=count*6;
         lcd.setCursor(2, 0);
         lcd.write(byte(1));
         lcd.setCursor(3, 0);
         lcd.write(byte(2));
         lcd.setCursor(4, 0);
         lcd.write(byte(3));
         lcd.setCursor(5, 0);
         lcd.write(byte(4));

         lcd.setCursor(2, 1);
         lcd.write(byte(5));
         lcd.setCursor(3, 1);
         lcd.write(byte(6));
         lcd.setCursor(4, 1);
         lcd.write(byte(7));
         lcd.setCursor(5, 1);
         lcd.write(byte(8));
         lcd.setCursor(7, 1);
 lcd.print(count);
 lcd.print(" BPM");
 temp=0;
 while(1);
}

