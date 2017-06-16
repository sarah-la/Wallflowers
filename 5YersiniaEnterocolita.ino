/*************************************************** 
  This is a example sketch demonstrating graphic drawing
  capabilities of the SSD1351 library for the 1.5" 
  and 1.27" 16-bit Color OLEDs with SSD1351 driver chip

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1431
  ------> http://www.adafruit.com/products/1673
 
  If you're using a 1.27" OLED, change SSD1351HEIGHT in Adafruit_SSD1351.h
   to 96 instead of 128

  These displays use SPI to communicate, 4 or 5 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

  The Adafruit GFX Graphics core library is also required
  https://github.com/adafruit/Adafruit-GFX-Library
  Be sure to install it!
 ****************************************************/

// You can use any (4 or) 5 pins 
#define sclk 13
#define mosi 12
#define dc   3

#define rst  7
#define cs   4
// Color definitions
#define  AntiqueWhite    0xFAEBD7
#define Aqua        0x00FFFF
#define Aquamarine      0x7FFFD4
#define Azure         0xF0FFFF
#define Beige         0xF5F5DC
#define Bisque        0xFFE4C4
#define Black         0x000000
#define BlanchedAlmond    0xFFEBCD
#define Blue        0x0000FF
#define BlueViolet      0x8A2BE2
#define Brown         0xA52A2A
#define BurlyWood       0xDEB887
#define CadetBlue       0x5F9EA0
#define Chartreuse      0x7FFF00
#define Chocolate       0xD2691E
#define Coral         0xFF7F50
#define CornflowerBlue    0x6495ED
#define Cornsilk      0xFFF8DC
#define Crimson       0xDC143C
#define Cyan        0x00FFFF
#define DarkBlue      0x00008B
#define DarkCyan      0x008B8B
#define DarkGoldenRod     0xB8860B
#define DarkGray      0xA9A9A9
#define DarkGrey      0xA9A9A9
#define DarkGreen       0x006400
#define DarkKhaki       0xBDB76B
#define DarkMagenta     0x8B008B
#define DarkOliveGreen    0x556B2F
#define DarkOrange      0xFF8C00
#define DarkOrchid      0x9932CC
#define DarkRed       0x8B0000
#define DarkSalmon      0xE9967A
#define DarkSeaGreen    0x8FBC8F
#define DarkSlateBlue     0x483D8B
#define DarkSlateGray     0x2F4F4F
#define DarkSlateGrey     0x2F4F4F
#define DarkTurquoise     0x00CED1
#define DarkViolet      0x9400D3
#define DeepPink      0xFF1493
#define DeepSkyBlue     0x00BFFF
#define DimGray       0x696969
#define DimGrey       0x696969
#define DodgerBlue      0x1E90FF
#define FireBrick       0xB22222
#define FloralWhite     0xFFFAF0
#define ForestGreen     0x228B22
#define Fuchsia       0xFF00FF
#define Gainsboro       0xDCDCDC
#define GhostWhite      0xF8F8FF
#define Gold        0xFFD700
#define GoldenRod       0xDAA520
#define Gray        0x808080
#define Grey        0x808080
#define Green         0x008000
#define GreenYellow     0xADFF2F
#define HoneyDew      0xF0FFF0
#define HotPink       0xFF69B4
#define IndianRed       0xCD5C5C
#define Indigo        0x4B0082
#define Ivory         0xFFFFF0
#define Khaki         0xF0E68C
#define Lavender      0xE6E6FA
#define LavenderBlush     0xFFF0F5
#define LawnGreen       0x7CFC00
#define LemonChiffon    0xFFFACD
#define LightBlue       0xADD8E6
#define LightCoral      0xF08080
#define LightCyan       0xE0FFFF
#define LightGoldenRodYellow 0xFAFAD2
#define LightGray       0xD3D3D3
#define LightGrey       0xD3D3D3
#define LightGreen      0x90EE90
#define LightPink       0xFFB6C1
#define LightSalmon     0xFFA07A
#define LightSeaGreen     0x20B2AA
#define LightSkyBlue    0x87CEFA
#define LightSlateGray    0x778899
#define LightSlateGrey    0x778899
#define LightSteelBlue    0xB0C4DE
#define LightYellow     0xFFFFE0
#define Lime        0x00FF00
#define LimeGreen       0x32CD32
#define Linen         0xFAF0E6
#define Magenta       0xFF00FF
#define Maroon        0x800000
#define MediumAquaMarine  0x66CDAA
#define MediumBlue      0x0000CD
#define MediumOrchid    0xBA55D3
#define MediumPurple    0x9370DB
#define MediumSeaGreen    0x3CB371
#define MediumSlateBlue   0x7B68EE
#define MediumSpringGreen   0x00FA9A
#define MediumTurquoise   0x48D1CC
#define MediumVioletRed   0xC71585
#define MidnightBlue    0x191970
#define MintCream       0xF5FFFA
#define MistyRose       0xFFE4E1
#define Moccasin      0xFFE4B5
#define NavajoWhite     0xFFDEAD
#define Navy        0x000080
#define OldLace       0xFDF5E6
#define Olive         0x808000
#define OliveDrab       0x6B8E23
#define Orange        0xFFA500
#define OrangeRed       0xFF4500
#define Orchid        0xDA70D6
#define PaleGoldenRod     0xEEE8AA
#define PaleGreen       0x98FB98
#define PaleTurquoise     0xAFEEEE
#define PaleVioletRed     0xDB7093
#define PapayaWhip      0xFFEFD5
#define PeachPuff       0xFFDAB9
#define Peru        0xCD853F
#define Pink        0xFFC0CB
#define Plum        0xDDA0DD
#define PowderBlue      0xB0E0E6
#define Purple        0x800080
#define RebeccaPurple     0x663399
#define Red         0xFF0000
#define RosyBrown       0xBC8F8F
#define RoyalBlue       0x4169E1
#define SaddleBrown     0x8B4513
#define Salmon        0xFA8072
#define SandyBrown      0xF4A460
#define SeaGreen      0x2E8B57
#define SeaShell      0xFFF5EE
#define Sienna        0xA0522D
#define Silver        0xC0C0C0
#define SkyBlue       0x87CEEB
#define SlateBlue       0x6A5ACD
#define SlateGray       0x708090
#define SlateGrey       0x708090
#define Snow        0xFFFAFA
#define SpringGreen     0x00FF7F
#define SteelBlue       0x4682B4
#define Tan         0xD2B48C
#define Teal        0x008080
#define Thistle       0xD8BFD8
#define Tomato        0xFF6347
#define Turquoise       0x40E0D0
#define Violet        0xEE82EE
#define Wheat         0xF5DEB3
#define White         0xFFFFFF
#define WhiteSmoke      0xF5F5F5
#define Yellow        0xFFFF00
#define YellowGreen     0x9ACD32



//#define BLACK           0x0000
//#define BLUE            0x001F
//#define RED             0xF800
//#define GREEN           0x07E0
//#define CYAN            0x07FF
//#define MAGENTA         0xF81F
//#define YELLOW          0xFFE0  
//#define WHITE           0xFFFF
//#define NAVY            0x000F      /*   0,   0, 128 */
//#define DARKGREEN       0x03E0      /*   0, 128,   0 */
//#define DARKCYAN        0x03EF      /*   0, 128, 128 */
//#define MAROON          0x7800      /* 128,   0,   0 */
//#define PURPLE          0x780F      /* 128,   0, 128 */
//#define OLIVE           0x7BE0      /* 128, 128,   0 */
//#define LIGHTGREY       0xC618      /* 192, 192, 192 */
//#define DARKGREY        0x7BEF      /* 128, 128, 128 */
//#define ORANGE          0xFD20      /* 255, 165,   0 */
//#define GREENYELLOW     0xAFE5      /* 173, 255,  47 */
//#define PINK                        0xF81F

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define pir A3              //pir for pir sensor
#define REDLITE 6                 //led RGB pins
#define GREENLITE 9
#define BLUELITE 11
int counter=1;
int j=0;

int slot=1;
int brightness = 255;
LiquidCrystal lcd(8,5,A0,A1,2,10); 
// Option 1: use any pins but a little slower
Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, mosi, sclk, rst);  


// Option 2: must use the hardware SPI pins 
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be 
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
//Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, rst);

float p = 3.1415926;

void fillpixelbypixel(uint16_t color) {
  for (uint8_t x=0; x < tft.width()/2; x++) {
    for (uint8_t y=0; y < tft.height()/2; y++) {
      tft.drawPixel(x, y, color);
    }
  }
  delay(100);
}

void setup(void) {
  Serial.begin(9600);
//  pinMode(cs2,OUTPUT);
  Serial.print("hello!");
  tft.begin();
lcd.begin(16, 2);
 lcd.print(" Welcome, Hello ");
  Serial.println("init");
 pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);
pinMode(pir,INPUT);
   brightness = 100;
  setBacklight(130, 255, 100);
  // You can optionally rotate the display by running the line below.
  // Note that a value of 0 means no rotation, 1 means 90 clockwise,
  // 2 means 180 degrees clockwise, and 3 means 270 degrees clockwise.
  //tft.setRotation(1);
  // NOTE: The test pattern at the start will NOT be rotated!  The code
  // for rendering the test pattern talks directly to the display and
  // ignores any rotation.

 
  
//  Serial.println(time, DEC);
  delay(500);
  
 // lcdTestPattern();
  //delay(500);
  
 /* tft.invert(true);
  delay(100);
  tft.invert(false);
  delay(100);

  tft.fillScreen(BLACK);
  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  delay(500);

  // tft print function!
  tftPrintTest();
  delay(500);
  
  //a single pixel
  tft.drawPixel(tft.width()/2, tft.height()/2, GREEN);
  delay(500);
*/
  // line draw test
 /* testlines(YELLOW);
  delay(500);    
 
  // optimized lines
  testfastlines(RED, BLUE);
  delay(500);    


  testdrawrects(GREEN);
  delay(1000);

  testfillrects(YELLOW, MAGENTA);
  delay(1000);

  tft.fillScreen(BLACK);
  testfillcircles(10, BLUE);
  testdrawcircles(10, WHITE);
  delay(1000);
   
  testroundrects();
  delay(500);*/

  for (uint8_t x=0; x < tft.width(); x++) {
    for (uint8_t y=0; y < tft.height(); y++) {
      tft.drawPixel(x, y, scalingFxn(Black));
    }
  }
  
  delay(500);
}

void loop() {

for (int i = 0; i < 255; i++) {
    setBacklight(i, 0, 255-i);
    delay(5);
  if(digitalRead(pir)==1){                       //pir code
  ++counter;
  i=0;
  if(counter>7){
    counter=1;
    }
    lcd.clear();
  motiondetected();
    
  slot=slot*-1;
  
  Serial.println(slot);  

Serial.println(counter);
  }
  }
  
  
  
  
  for (int i = 0; i < 255; i++) {
    setBacklight(255-i, i, 0);
    delay(5);
  if(digitalRead(pir)==1){                       //pir code
  ++counter;
  i=0;
  if(counter>7){
    counter=1;
    }
    lcd.clear();
  motiondetected();
    
  slot=slot*-1;
  
  Serial.println(slot);  

Serial.println(counter);
  }
  }
 
  
  
  
  
  
  for (int i = 0; i < 255; i++) {
  setBacklight(0, 255-i, i);
    delay(5);
if(digitalRead(pir)==1){                       //pir code
  ++counter;
  i=0;
  if(counter>7){
    counter=1;
    }
    lcd.clear();
  motiondetected();
    
  slot=slot*-1;
  
  Serial.println(slot);  

Serial.println(counter);
  }
  }


}
/*
void testlines(uint16_t color) {
   tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-1; x+=6) {
     tft.drawLine(0, 0, x, tft.height()-1, color);
   }
   for (uint16_t y=0; y < tft.height()-1; y+=6) {
     tft.drawLine(0, 0, tft.width()-1, y, color);
   }
   
   tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-1; x+=6) {
     tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);
   }
   for (uint16_t y=0; y < tft.height()-1; y+=6) {
     tft.drawLine(tft.width()-1, 0, 0, y, color);
   }
   
   tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-1; x+=6) {
     tft.drawLine(0, tft.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < tft.height()-1; y+=6) {
     tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);
   }

   tft.fillScreen(BLACK);
   for (uint16_t x=0; x < tft.width()-1; x+=6) {
     tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < tft.height()-1; y+=6) {
     tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);
   }
   
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0,0);
  tft.setTextColor(color);
  tft.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2) {
   tft.fillScreen(BLACK);
   for (uint16_t y=0; y < tft.height()-1; y+=5) {
     tft.drawFastHLine(0, y, tft.width()-1, color1);
   }
   for (uint16_t x=0; x < tft.width()-1; x+=5) {
     tft.drawFastVLine(x, 0, tft.height()-1, color2);
   }
}

void testdrawrects(uint16_t color) {
 tft.fillScreen(BLACK);
 for (uint16_t x=0; x < tft.height()-1; x+=6) {
   tft.drawRect((tft.width()-1)/2 -x/2, (tft.height()-1)/2 -x/2 , x, x, color);
 }
}

void testfillrects(uint16_t color1, uint16_t color2) {
 tft.fillScreen(BLACK);
 for (uint16_t x=tft.height()-1; x > 6; x-=6) {
   tft.fillRect((tft.width()-1)/2 -x/2, (tft.height()-1)/2 -x/2 , x, x, color1);
   tft.drawRect((tft.width()-1)/2 -x/2, (tft.height()-1)/2 -x/2 , x, x, color2);
 }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (uint8_t x=radius; x < tft.width()-1; x+=radius*2) {
    for (uint8_t y=radius; y < tft.height()-1; y+=radius*2) {
      tft.fillCircle(x, y, radius, color);
    }
  }  
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (uint8_t x=0; x < tft.width()-1+radius; x+=radius*2) {
    for (uint8_t y=0; y < tft.height()-1+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }  
}*/
/*
void testtriangles() {
  tft.fillScreen(BLACK);
  int color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height();
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t+=1) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}*/
/*
void testroundrects() {
  tft.fillScreen(BLACK);
  int color = 100;
  
  int x = 0;
  int y = 0;
  int w = tft.width();
  int h = tft.height();
  for(int i = 0 ; i <= 24; i++) {
    tft.drawRoundRect(x, y, w, h, 5, color);
    x+=2;
    y+=3;
    w-=4;
    h-=6;
    color+=1100;
    Serial.println(i);
  }
}

void tftPrintTest() {
  tft.fillScreen(BLACK);
  tft.setCursor(0, 5);
  tft.setTextColor(RED);  
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(BLUE);
  tft.setTextSize(3);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 5);
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(WHITE);
  tft.print(" seconds.");
}

void mediabuttons() {
 // play
  tft.fillScreen(BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, GREEN);
}*/

/**************************************************************************/
/*! 
    @brief  Renders a simple test pattern on the LCD
*/
/**************************************************************************/
void lcdTestPattern(void)
{
  uint32_t i,j;
  tft.goTo(0, 0);
  
  for(i=0;i<128;i++)
  {
    for(j=0;j<128;j++)
    {
      if(i<16){
        tft.writeData(scalingFxn(Red)>>8); tft.writeData(scalingFxn(Red));
      }
      else if(i<32) {
        tft.writeData(scalingFxn(Yellow)>>8);tft.writeData(scalingFxn(Yellow));
      }
      else if(i<48){tft.writeData(scalingFxn(Green)>>8);tft.writeData(scalingFxn(Green));}
      else if(i<64){tft.writeData(scalingFxn(Cyan)>>8);tft.writeData(scalingFxn(Cyan));}
      else if(i<80){tft.writeData(scalingFxn(Blue)>>8);tft.writeData(scalingFxn(Blue));}
      else if(i<96){tft.writeData(scalingFxn(Magenta)>>8);tft.writeData(scalingFxn(Magenta));}
      else if(i<112){tft.writeData(scalingFxn(Black)>>8);tft.writeData(scalingFxn(Black));}
      else {
        tft.writeData(scalingFxn(White)>>8);      
        tft.writeData(scalingFxn(White));
       }
    }
  }
}


void setBacklight(uint8_t r, uint8_t g, uint8_t b) {
  // normalize the red LED - its brighter than the rest!
  r = map(r, 0, 255, 0, 100);
  g = map(g, 0, 255, 0, 150);
 
  r = map(r, 0, 255, 0, brightness);
  g = map(g, 0, 255, 0, brightness);
  b = map(b, 0, 255, 0, brightness);
 
  // common anode so invert!
  r = map(r, 0, 255, 255, 0);
  g = map(g, 0, 255, 255, 0);
  b = map(b, 0, 255, 255, 0);
  //Serial.print("R = "); Serial.print(r, DEC);
  //Serial.print(" G = "); Serial.print(g, DEC);
  //Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}


void motiondetected(){
 
 if(counter==1) {
  
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("I was still able");
 lcd.setCursor(0,1);
 lcd.print("to drink in high");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("school. I drank ");
lcd.setCursor(0,1);
lcd.print("alot. Good fun..");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("The first time I");
lcd.setCursor(0,1);
lcd.print(" realized I had ");
Serial.println("    parade    ");}  

else if(counter==2){
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("serious allergy ");
 lcd.setCursor(0,1);
 lcd.print("definitively was");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("in college. A Dr");
lcd.setCursor(0,1);
lcd.print(" discovered the ");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("alcohol & other ");
lcd.setCursor(0,1);
lcd.print("allergic things.");
Serial.println("    response    ");  
  }


else if(counter==3){
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("Diseases can be ");
 lcd.setCursor(0,1);
 lcd.print("  the cause of  ");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print(" changes in the ");
lcd.setCursor(0,1);
lcd.print("body that cause ");
delay(2000);
 lcd.setCursor(0,0);
lcd.print(" allergies and  ");
lcd.setCursor(0,1);
lcd.print(" other problems."); 
Serial.println("    maleable.   "); 
  }
  
else if(counter==4){
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print(" Nobody really  ");
 lcd.setCursor(0,1);
 lcd.print("knows everything");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("that's out there");
lcd.setCursor(0,1);
lcd.print(" many pathogens.");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("I want people to");
lcd.setCursor(0,1);
lcd.print(" do their best. "); 
  Serial.println("other like warriors");
  }

  
else if(counter==5){
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
   lcd.setCursor(0,0);
lcd.print("    Develop a   ");
 lcd.setCursor(0,1);
 lcd.print("vaccine against ");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("  one thing and ");
lcd.setCursor(0,1);
lcd.print("  accidentally  ");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("  cause other   ");
lcd.setCursor(0,1);
lcd.print("   problems.    "); 
Serial.println("places at home.");
  }

  
else if(counter==6){
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
   lcd.setCursor(0,0);
lcd.print("Denial is not a ");
 lcd.setCursor(0,1);
 lcd.print(" viable option. ");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("I must always be");
lcd.setCursor(0,1);
lcd.print("finding solving ");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("my problems. No ");
lcd.setCursor(0,1);
lcd.print("matter how hard.");
Serial.println("   blahblah   ");}

  
else if(counter==7){
 
  fillpixelbypixel(tft.Color565(20, 0, 20));
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("It's hard for me");
 lcd.setCursor(0,1);
 lcd.print("to identify what");
 delay(2000);
 lcd.setCursor(0,0);
lcd.print("my problems are,");
lcd.setCursor(0,1);
lcd.print("to separate thru");
delay(2000);
 lcd.setCursor(0,0);
lcd.print("everything in me");
lcd.setCursor(0,1);
lcd.print("and decide & act");
Serial.println("  many times.  ");  
  }
}

uint16_t scalingFxn(uint8_t _red, uint8_t _green, uint8_t _blue) {
  uint16_t rescaled_color = 0; 
  rescaled_color = (((_red * 249 + 1014) >> 11)<<11) | (((_green * 253 + 505) >> 10)<<5) | ((_blue * 249 + 1014) >> 11);
  return rescaled_color;
}

uint16_t scalingFxn(int _24bitcolor) {
  uint16_t rescaled_color = 0;
  uint8_t _red; 
  uint8_t _green; 
  uint8_t _blue;
  _red = _24bitcolor >> 16;
  _green = _24bitcolor >> 8;
  _blue = _24bitcolor;
  rescaled_color = (((31*(_red+4))/255)<<11) | (((63*(_green+2))/255)<<5) | ((31*(_blue+4))/255);
  return rescaled_color;
}
