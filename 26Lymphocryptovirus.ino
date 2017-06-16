// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
//#include <Adafruit_NeoPixel.h>
//#include <Wire.h>
//#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
 
#define REDLITE 3
#define GREENLITE 5
#define BLUELITE 6
#define pir A3
#define pir2 A5
//pir for pir sensor


bool toggle_pir = false;
bool pir_timer = false;
uint32_t timer   = 0;

uint32_t color_timer   = 0;
uint8_t brightness = 100;

bool r_flag = true;
bool g_flag = true;
bool b_flag = true;

uint8_t i, j, k = 0;
 
// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12,11,10,9,8,7);
LiquidCrystal lcd(4,8,9,10,11,12); 
// you can change the overall brightness by range 0 -> 255
//int brightness = 255;
 int flag=0;
//#define PIN 9 //NEO pixels to arduino pin12
//#define NUMPIXELS 8
// Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Are some behaviours ");
  lcd.setCursor(0,1);
  lcd.print(" so ingrained, one  ");
    lcd.setCursor(0,2);
     lcd.print(" generation to the  ");
      lcd.setCursor(0,3);
     lcd.print("next that they cause");
  pinMode(pir,INPUT);
  digitalWrite(pir,LOW);
  pinMode(pir2,INPUT);
  digitalWrite(pir2,LOW);
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);
  randomSeed(analogRead(A1));


  matrix.begin(0x70); 
//  pinMode(pir,INPUT);
//  Serial.begin(9600);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
//  pixels.setBrightness(150);// 0-255
//  pixels.begin();
 
  brightness = 100;
}
 
void loop() {
  lcdDisplay();
  lcdLuxCTRL();
  pixel_eyes();
  pir_timer = ((millis() - timer) >= 16000) ? true : false; 
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
  Serial.print("R = "); Serial.print(r, DEC);
  Serial.print(" G = "); Serial.print(g, DEC);
  Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}

void lcdCtrl(uint8_t _rand) {
  switch (_rand) {
    
    case 0:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Are some behaviours "));
    lcd.setCursor(0,1);
    lcd.print(F(" so ingrained, one  "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("  generation to the "));
    lcd.setCursor(0,3);
    lcd.print(F("next that they cause"));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("permanent, dominant,"));
    lcd.setCursor(0,1);
    lcd.print(F("and compounding gene"));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("changes to each new "));
    lcd.setCursor(0,3);
    lcd.print(F("generation, one and "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F(" then the next and  "));
    lcd.setCursor(0,1);
    lcd.print(F(" so on? Researchers "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" are looking at it. "));
    lcd.setCursor(0,3);
    lcd.print(F("It appears it is so."));
    Serial.println(F("    parade    "));
    delay(3000);
    break;
    
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" Did you know that  "));
    lcd.setCursor(0,1);
    lcd.print(F("when you excercise, "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("  at least 10,000   "));
    lcd.setCursor(0,3);
    lcd.print(F(" different chemical "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("  reactions occur?  "));
    lcd.setCursor(0,1);
    lcd.print(F(" That is an amazing "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" fact. Mindblowing, "));
    lcd.setCursor(0,3);
    lcd.print(F("to me. Biochemistry "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("  is a fascinating  "));
    lcd.setCursor(0,1);
    lcd.print(F("topic in my opinion."));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" The combination of "));
    lcd.setCursor(0,3);
    lcd.print(F("genes and violence.."));                                                                                                          
    Serial.println(F("    response    "));
    delay(3000);
    break;
    
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Genetic engineering "));
    lcd.setCursor(0,1);
    lcd.print(F(" might someday make "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("it possible to alter"));
    lcd.setCursor(0,3);
    lcd.print(F("genes back to their "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("  original states,  "));
    lcd.setCursor(0,1);
    lcd.print(F(" perhaps providing "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" healthier, longer  "));
    lcd.setCursor(0,3);
    lcd.print(F("  lives to people.  "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("I think the next 20 "));
    lcd.setCursor(0,1);
    lcd.print(F("years will be crazy "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("  for breakthroughs "));
    lcd.setCursor(0,3);
    lcd.print(F("   in medicine...   "));
    Serial.println(F("    maleable.   ")); 
    delay(3000);
    break;
    
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I hope that whatever"));
    lcd.setCursor(0,1);
    lcd.print(F("happens in research "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("benefits the poor as"));
    lcd.setCursor(0,3);
    lcd.print(F("  well as the rich. "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F(" my greatest hope.  "));
    lcd.setCursor(0,1);
    lcd.print(F("  I fear the worst, "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("  however. Already  "));
    lcd.setCursor(0,3);
    lcd.print(F(" widespread gaps in "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("the quality of care,"));
    lcd.setCursor(0,1);
    lcd.print(F("and the way that the"));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("  entire system is  "));
    lcd.setCursor(0,3);
    lcd.print(F("set up. Needs change")); 
    Serial.println(F("other like warriors"));
    delay(3000);
    break;
    
    case 4:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Our systems need to "));
    lcd.setCursor(0,1);
    lcd.print(F(" look at quality of "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("life for all and not"));
    lcd.setCursor(0,3);
    lcd.print(F("be so profit driven."));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("But profit is human "));
    lcd.setCursor(0,1);
    lcd.print(F("nature, and I accept"));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("that. I don't accept"));
    lcd.setCursor(0,3);
    lcd.print(F("obscene profit while"));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("the masses suffer..."));
    lcd.setCursor(0,1);
    lcd.print(F(" Although I realize "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("that the definition "));
    lcd.setCursor(0,3);
    lcd.print(F("is very subjective. ")); 
    Serial.println(F("places at home."));
    delay(3000);
    break;
    
    case 5:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Change is not a bad "));
    lcd.setCursor(0,1);
    lcd.print(F("thing. Needs vision,"));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("that's all.  And it "));
    lcd.setCursor(0,3);
    lcd.print(F(" needs motivation.  "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("Change costs money. "));
    lcd.setCursor(0,1);
    lcd.print(F("  And it sometimes  "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("requires agreement, "));
    lcd.setCursor(0,3);
    lcd.print(F("which can be slow & "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F("difficult, and cost "));
    lcd.setCursor(0,1);
    lcd.print(F(" valuable resources "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("I believe in change "));
    lcd.setCursor(0,3);
    lcd.print(F("will always believe."));
    Serial.println(F("   blahblah   "));
    delay(3000);
    break;
    
    case 6:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("What about personal "));
    lcd.setCursor(0,1);
    lcd.print(F(" change? It is also "));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" time consuming and "));
    lcd.setCursor(0,3);
    lcd.print(F(" expensive...but is "));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F(" ultimatley always  "));
    lcd.setCursor(0,1);
    lcd.print(F("worth it, I believe."));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F("I'm scared of change"));
    lcd.setCursor(0,3);
    lcd.print(F("in any form. I'm not"));
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print(F(" Exactly sure where "));
    lcd.setCursor(0,1);
    lcd.print(F("that fear comes from"));
//    delay(3000);
    lcd.setCursor(0,2);
    lcd.print(F(" Just comforted by  "));
    lcd.setCursor(0,3);
    lcd.print(F("the known, I guess.."));
    Serial.println(F("  many times.  ")); 
    delay(3000);
    break;
  }
}

void lcdDisplay() {
  if((digitalRead(pir) || digitalRead(pir2)) && pir_timer) {
  timer = millis();
  toggle_pir = !toggle_pir;
  lcdCtrl(random(7));
//    Serial.println("pir");
  }
}

void lcdLuxCTRL() {
  if((millis() - color_timer) >= 20 ) {
    color_timer = millis();
    setBacklight(i, j, k);
    
    if (i == 255) {
      r_flag = false;
    }
    
    if (i == 0) {
      r_flag = true;
    }
    
    if (r_flag) {
      i++;
    }
    
    if (!r_flag) {
      i--;
    }

    if (j == 255) {
      g_flag = false;
    }
    
    if (j == 0) {
      g_flag = true;
    }
    
    if (g_flag) {
//      j += 5;
    }
    
    if (!g_flag) {
//      j -= 5;
    }

    if (k == 254) {
      b_flag = false;
    }
    
    if (k == 0) {
      b_flag = true;
    }
    
    if (b_flag) {
      k += 2;
    }
    
    if (!b_flag) {
      k -= 2;
    }
  }
}

void oldpixelCode() {
  for (int i = 0; i < 255; i++) {
    setBacklight(i, 0, 255-i);
    delay(5);
    lcdDisplay();
  }
  for (int i = 0; i < 255; i++) {
    setBacklight(255-i, i, 0);
    delay(5);
    if(digitalRead(2)==1){
    flag=1;}
  }
  for (int i = 0; i < 255; i++) {
    setBacklight(0, 255-i, i);
    delay(5);
    if(digitalRead(2)==1){
    flag=1;}
  }

  if(flag==1){
    lcd.setCursor(2,0);
    lcd.print("    PIR motion   ");
    delay(2000);
    lcd.clear();
    flag=0;
  }
}

void pixel_eyes() {
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  Serial.println(digitalRead(pir));
  if(digitalRead(pir)==0){
  Serial.println("PIR Alert");
  
//  for(int i=0;i<NUMPIXELS;i++){
//  
//  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//  pixels.setPixelColor(i, pixels.Color(255,120,0)); // color set to orange
//  
//  pixels.show(); // This sends the updated pixel color to the hardware.
//  
//  delay(50); // Delay for a period of time (in milliseconds).
//  }
  
  
  ++flag;
  if(flag>2){
  flag=0;
  }
  matrix.clear(); 
  while(digitalRead(pir)==0);
  }
  delay(100);
  
//  for(int i=0;i<NUMPIXELS;i++){
//  
//  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//  pixels.setPixelColor(i, pixels.Color(255,255,0)); // color set to yellow
//  
//  pixels.show(); // This sends the updated pixel color to the hardware.
//  delay(50); // Delay for a period of time (in milliseconds).
//  
//  }
  
  if(flag==0){
    matrix.clear();
    matrix.fillRect(2,2, 4,4, LED_ON);
    matrix.writeDisplay(); 
  }
  else if(flag==1){
   matrix.clear();
   matrix.fillRect(2,2, 4,4, LED_ON);
    matrix.writeDisplay(); 
  }
  
  else{
  
    matrix.fillRect(0,0, 8,8, LED_ON);
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(500);
  
  } 
  
  

}
