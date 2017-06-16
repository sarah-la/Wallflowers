// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h>
 
#define REDLITE 3
#define GREENLITE 5
#define BLUELITE 6
#define pir A4
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
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("RGB 16x2 oneone  ");
  lcd.setCursor(0,1);
  lcd.print(" Multicolor one ");
  pinMode(pir,INPUT);
  digitalWrite(pir,LOW);
  pinMode(pir2,INPUT);
  digitalWrite(pir2,LOW);
  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);
  randomSeed(analogRead(A1));
 
  brightness = 100;
}
 
void loop() {
  lcdDisplay();
  lcdLuxCTRL();
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
    lcd.print(F("To be flawed is "));
    lcd.setCursor(0,1);
    lcd.print(F(" okay with me..."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Better to try a "));
    lcd.setCursor(0,1);
    lcd.print(F("thing and learn."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Perfectionism is"));
    lcd.setCursor(0,1);
    lcd.print(F("something I dont"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  worry about.  "));
    lcd.setCursor(0,1);
    lcd.print(F("Today was great,"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("it wasnt perfect"));
    lcd.setCursor(0,1);
    lcd.print(F("and one can try "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" to strive for  "));
    lcd.setCursor(0,1);
    lcd.print(F("better in future"));
    Serial.println(F("    parade    "));
    delay(2000);
    break;
    
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("What matters to "));
    lcd.setCursor(0,1);
    lcd.print(F("me is learning, "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" improving, and "));
    lcd.setCursor(0,1);
    lcd.print(F("growing.  Being "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("happy is also so"));
    lcd.setCursor(0,1);
    lcd.print(F("important to me."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I want to treat "));
    lcd.setCursor(0,1);
    lcd.print(F("others well:with"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("respect and with"));
    lcd.setCursor(0,1);
    lcd.print(F("tolerance, and I"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  also do treat "));
    lcd.setCursor(0,1);
    lcd.print(F("  myself well.  "));                                                                                                          
    Serial.println(F("    response    "));
    delay(2000);
    break;
    
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("  What does it  "));
    lcd.setCursor(0,1);
    lcd.print(F("mean to listen  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("   to oneself?  "));
    lcd.setCursor(0,1);
    lcd.print(F("It is not black "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("and white, it is"));
    lcd.setCursor(0,1);
    lcd.print(F(" on a spectrum, "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("there are levels"));
    lcd.setCursor(0,1);
    lcd.print(F("of listening to "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" oneself and to "));
    lcd.setCursor(0,1);
    lcd.print(F("knowing oneself."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" Life is a maze."));
    lcd.setCursor(0,1);
    lcd.print(F(" Hard to know..."));
    Serial.println(F("    maleable.   ")); 
    delay(2000);
    break;
    
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" Some people, I "));
    lcd.setCursor(0,1);
    lcd.print(F(" look at them & "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Im in the moment"));
    lcd.setCursor(0,1);
    lcd.print(F("there is nothing"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" going on in my "));
    lcd.setCursor(0,1);
    lcd.print(F("head.  And then "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F( "some people, I "));
    lcd.setCursor(0,1);
    lcd.print(F("look at them and"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("am attracted and"));
    lcd.setCursor(0,1);
    lcd.print(F("there is alot of"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" thoughts going "));
    lcd.setCursor(0,1);
    lcd.print(F("on in my head.. ")); 
    Serial.println(F("other like warriors"));
    delay(2000);
    break;
    
    case 4:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" I will be more "));
    lcd.setCursor(0,1);
    lcd.print(F("open to myself, "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" and to others, "));
    lcd.setCursor(0,1);
    lcd.print(F("its good for me "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("to be more open "));
    lcd.setCursor(0,1);
    lcd.print(F("to possibilities"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" and to all the "));
    lcd.setCursor(0,1);
    lcd.print(F("mystery of life."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("The path itself "));
    lcd.setCursor(0,1);
    lcd.print(F(" and how I walk "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" on the path is "));
    lcd.setCursor(0,1);
    lcd.print(F("important to me.")); 
    Serial.println(F("places at home."));
    delay(2000);
    break;
    
    case 5:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" To make a plan "));
    lcd.setCursor(0,1);
    lcd.print(F("  and to have a "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" goal are good, "));
    lcd.setCursor(0,1);
    lcd.print(F(" these are good "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" Things.  And I "));
    lcd.setCursor(0,1);
    lcd.print(F("must remember to"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" have fun along "));
    lcd.setCursor(0,1);
    lcd.print(F(" the way.  This "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("balancing act is"));
    lcd.setCursor(0,1);
    lcd.print(F(" a difficulty I "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("face, constantly"));
    lcd.setCursor(0,1);
    lcd.print(F("I try my best..."));
    Serial.println(F("   blahblah   "));
    delay(2000);
    break;
    
    case 6:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Am I talking too"));
    lcd.setCursor(0,1);
    lcd.print(F("much? Revealing "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("too much?  I do "));
    lcd.setCursor(0,1);
    lcd.print(F("worry about that"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" It's important "));
    lcd.setCursor(0,1);
    lcd.print(F("  to say what I "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("need to say, and"));
    lcd.setCursor(0,1);
    lcd.print(F(" to get what I  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("need in any type"));
    lcd.setCursor(0,1);
    lcd.print(F(" of situation,  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("when working with"));
    lcd.setCursor(0,1);
    lcd.print(F(" other people.  "));
    Serial.println(F("  many times.  ")); 
    delay(2000);
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
    lcd.setCursor(0,1);
    lcd.print("    PIR motion   ");
    delay(2000);
    lcd.clear();
    flag=0;
  }
}
