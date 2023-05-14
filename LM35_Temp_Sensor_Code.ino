

/* 
 20 character 4 line I2C Display
 Backpack Interface labelled "YwRobot Arduino LCM1602 IIC V1"
 Connections:-
 Vcc to 5V (Red) 
 Ground (Gnd) to Ground (Gnd) (Black)
 SDA to A4 (Blue)
 SCL to A5 (yellow)
*/

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads

#include <LiquidCrystal_I2C.h>
float temp; //Variable where we will stock the temperature value 
int tempPin = 0; //Pin used with the sensor output here it's A0 
 

// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup() {  

Serial.begin(9600);  
lcd.begin (20,4);  

} 
void loop() {  

temp = analogRead(tempPin); //Reading the value from the analog input
temp = temp * 500/1023; //Sensor calibration to get the real value 
lcd.clear(); 
lcd.setCursor (0,0); //Start writing on 0.0 on lcd screen
lcd.print("Temperature"); 
lcd.setCursor (0,1); 
lcd.print(temp); //Temperature value
lcd.print ((" C")); //Celsius of course :D
delay(1000); //Refresh every 1s 
}
