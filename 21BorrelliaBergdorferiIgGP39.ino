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
  lcd.print("RGB 16x2 Dithree  ");
  lcd.setCursor(0,1);
  lcd.print(" Multithree LCD ");
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
    lcd.print(F("I am allergic to"));
    lcd.setCursor(0,1);
    lcd.print(F(" certain things "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("one of them is "));
    lcd.setCursor(0,1);
    lcd.print(F("  penecillin.   "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("We found out at "));
    lcd.setCursor(0,1);
    lcd.print(F("  the doctor's. "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I found out alot"));
    lcd.setCursor(0,1);
    lcd.print(F("of things at the"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("doctor's office."));
    lcd.setCursor(0,1);
    lcd.print(F("More than anyone"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("should ever have"));
    lcd.setCursor(0,1);
    lcd.print(F("   to know...   "));
    Serial.println(F("    parade    "));
    delay(2000);
    break;
    
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("The sound of my "));
    lcd.setCursor(0,1);
    lcd.print(F("voice trails off"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("and fades, quiet"));
    lcd.setCursor(0,1);
    lcd.print(F(" Contemplative. "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I remain silent "));
    lcd.setCursor(0,1);
    lcd.print(F("for a long time."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Feeling.  Being."));
    lcd.setCursor(0,1);
    lcd.print(F("Maybe a bit numb"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("My world is full"));
    lcd.setCursor(0,1);
    lcd.print(F("of danger I feel"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I feel...I feel "));
    lcd.setCursor(0,1);
    lcd.print(F("Hoping to feel.."));                                                                                                          
    Serial.println(F("    response    "));
    delay(2000);
    break;
    
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" I take a break,"));
    lcd.setCursor(0,1);
    lcd.print(F("and contemplate."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("How I am like a "));
    lcd.setCursor(0,1);
    lcd.print(F("weed in the lawn"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("It's hard to get"));
    lcd.setCursor(0,1);
    lcd.print(F("rid of me.  I'm "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" everywhere and "));
    lcd.setCursor(0,1);
    lcd.print(F(" nowhere.  I am "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" boundary-less. "));
    lcd.setCursor(0,1);
    lcd.print(F(" Without bounds "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Family binds me."));
    lcd.setCursor(0,1);
    lcd.print(F("bound and found."));
    Serial.println(F("    maleable.   ")); 
    delay(2000);
    break;
    
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I want to go far"));
    lcd.setCursor(0,1);
    lcd.print(F(" I want to fly. "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I am free and I "));
    lcd.setCursor(0,1);
    lcd.print(F("want to be more "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I'm glad I know "));
    lcd.setCursor(0,1);
    lcd.print(F(" my own history."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I would be lost "));
    lcd.setCursor(0,1);
    lcd.print(F("without it.  And"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("sometimes it is "));
    lcd.setCursor(0,1);
    lcd.print(F(" a very painful "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("topic.  Hard to "));
    lcd.setCursor(0,1);
    lcd.print(F("  speak about.  ")); 
    Serial.println(F("other like warriors"));
    delay(2000);
    break;
    
    case 4:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("So anyway, I am "));
    lcd.setCursor(0,1);
    lcd.print(F(" allergic to: 1 "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" alcohol, and 2 "));
    lcd.setCursor(0,1);
    lcd.print(F("penecillin. This"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("is where I start"));
    lcd.setCursor(0,1);
    lcd.print(F(" and where I go,"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I live in a time"));
    lcd.setCursor(0,1);
    lcd.print(F(" of warriors, I "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("cannot show that"));
    lcd.setCursor(0,1);
    lcd.print(F("I feel weak and "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("scared. I don't "));
    lcd.setCursor(0,1);
    lcd.print(F("  feel anything ")); 
    Serial.println(F("places at home."));
    delay(2000);
    break;
    
    case 5:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" My weakness is "));
    lcd.setCursor(0,1);
    lcd.print(F("my greatest gift"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I truly believe "));
    lcd.setCursor(0,1);
    lcd.print(F("My big problems "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" have become my "));
    lcd.setCursor(0,1);
    lcd.print(F(" huge strengths."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" The scenes I   "));
    lcd.setCursor(0,1);
    lcd.print(F(" navigated as a "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("toddler & child "));
    lcd.setCursor(0,1);
    lcd.print(F("were complicated"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" And permanently"));
    lcd.setCursor(0,1);
    lcd.print(F("  altered me.   "));
    Serial.println(F("   blahblah   "));
    delay(2000);
    break;
    
    case 6:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I talk about in "));
    lcd.setCursor(0,1);
    lcd.print(F(" art the things "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" I have trouble "));
    lcd.setCursor(0,1);
    lcd.print(F(" talking about. "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("It feels good to"));
    lcd.setCursor(0,1);
    lcd.print(F("talk. very good "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("It's healthy to "));
    lcd.setCursor(0,1);
    lcd.print(F("talk.  Good for "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("the body,  good "));
    lcd.setCursor(0,1);
    lcd.print(F("  for the soul.  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Healing Activity"));
    lcd.setCursor(0,1);
    lcd.print(F(" mind body soul "));
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
