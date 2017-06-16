#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


#define pir A3 //pir to arduino pin3 ** Changed from A4 to A3 to avoid conflict with I2C bus
#define PIN 3 //NEO pixels to arduino pin12
#define NUMPIXELS 8

int flag=0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
void setup() {
// put your setup code here, to run once:
matrix.begin(0x70); 
pinMode(pir,INPUT);
Serial.begin(9600);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
pixels.setBrightness(150);// 0-255
pixels.begin();
}

static const uint8_t PROGMEM
smile_bmp[] =
{ B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B10011001,
B01000010,
B00111100 },
neutral_bmp[] =
{ B00111100,
B01000010,
B10100101,
B10000001,
B10111101,
B10000001,
B01000010,
B00111100 },
frown_bmp[] =
{ B00111100,
B01000010,
B10100101,
B10000001,
B10011001,
B10100101,
B01000010,
B00111100 };




void loop() {
// put your main code here, to run repeatedly:
digitalWrite(8,LOW);
digitalWrite(9,LOW);
Serial.println(digitalRead(pir));
if(digitalRead(pir)==0){
Serial.println("PIR Alert");

for(int i=0;i<NUMPIXELS;i++){

// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
pixels.setPixelColor(i, pixels.Color(255,120,0)); // color set to orange

pixels.show(); // This sends the updated pixel color to the hardware.

delay(50); // Delay for a period of time (in milliseconds).
}


++flag;
if(flag>2){
flag=0;
}
matrix.clear(); 
while(digitalRead(pir)==0);
}
delay(100);

for(int i=0;i<NUMPIXELS;i++){

// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
pixels.setPixelColor(i, pixels.Color(255,255,0)); // color set to yellow

pixels.show(); // This sends the updated pixel color to the hardware.
delay(50); // Delay for a period of time (in milliseconds).

}

if(flag==0){
  matrix.clear();
  matrix.fillRect(1,1, 5,5, LED_ON);
  matrix.writeDisplay(); 
}
else if(flag==1){
 matrix.clear();
 matrix.fillRect(1,1, 5,5, LED_ON);
  matrix.writeDisplay(); 
}

else{

  matrix.fillRect(0,0, 8,8, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

} 



}
  

