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
  lcd.print("RGB 16x2 twotwoy  ");
  lcd.setCursor(0,1);
  lcd.print(" Multicolor two ");
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
    lcd.print(F("In high school I"));
    lcd.setCursor(0,1);
    lcd.print(F(" fainted while  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" running a race."));
    lcd.setCursor(0,1);
    lcd.print(F(" I also dieted  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("to the point of "));
    lcd.setCursor(0,1);
    lcd.print(F("    anorexia.   "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  When another  "));
    lcd.setCursor(0,1);
    lcd.print(F("took control of "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("me, my response "));
    lcd.setCursor(0,1);
    lcd.print(F("was to take back"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("control whatever"));
    lcd.setCursor(0,1);
    lcd.print(F("  way I could..."));
    Serial.println(F("    parade    "));
    delay(2000);
    break;
    
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" Controlling is "));
    lcd.setCursor(0,1);
    lcd.print(F(" not loving. It "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("is hard; loving "));
    lcd.setCursor(0,1);
    lcd.print(F(" is soft, quiet "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  tolerant and  "));
    lcd.setCursor(0,1);
    lcd.print(F("intimate, inner "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("focused, looking"));
    lcd.setCursor(0,1);
    lcd.print(F(" Also sometimes "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("love is action, "));
    lcd.setCursor(0,1);
    lcd.print(F("and making ones "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" point of view  "));
    lcd.setCursor(0,1);
    lcd.print(F(" crystal clear. "));                                                                                                          
    Serial.println(F("    response    "));
    delay(2000);
    break;
    
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("So I controlled "));
    lcd.setCursor(0,1);
    lcd.print(F(" what I could,  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("what I would eat"));
    lcd.setCursor(0,1);
    lcd.print(F("because it was  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("the only thing I"));
    lcd.setCursor(0,1);
    lcd.print(F(" had power over."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("I turned invward"));
    lcd.setCursor(0,1);
    lcd.print(F("because I could "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("see confronting "));
    lcd.setCursor(0,1);
    lcd.print(F(" those in power: "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" not an option  "));
    lcd.setCursor(0,1);
    lcd.print(F("that would work."));
    Serial.println(F("    maleable.   ")); 
    delay(2000);
    break;
    
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("How to feel ones"));
    lcd.setCursor(0,1);
    lcd.print(F("power as a human"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  when I was a  "));
    lcd.setCursor(0,1);
    lcd.print(F("powerless child?"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("learning ways of"));
    lcd.setCursor(0,1);
    lcd.print(F("being, behaving "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("and not learning"));
    lcd.setCursor(0,1);
    lcd.print(F("  enough about  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  boundaries,  "));
    lcd.setCursor(0,1);
    lcd.print(F("my own feelings,"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("only a puppet of"));
    lcd.setCursor(0,1);
    lcd.print(F("others' feelings")); 
    Serial.println(F("other like warriors"));
    delay(2000);
    break;
    
    case 4:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Powerlessness is"));
    lcd.setCursor(0,1);
    lcd.print(F("a scary thing to"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("me. Terrifying, "));
    lcd.setCursor(0,1);
    lcd.print(F("I've been there."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("It is said that "));
    lcd.setCursor(0,1);
    lcd.print(F("people that have"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("been badly hurt "));
    lcd.setCursor(0,1);
    lcd.print(F(" go on later to "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("hurt others.They"));
    lcd.setCursor(0,1);
    lcd.print(F("are dangerous to"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("themselves & to "));
    lcd.setCursor(0,1);
    lcd.print(F("others...broken ")); 
    Serial.println(F("places at home."));
    delay(2000);
    break;
    
    case 5:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" The mistake is "));
    lcd.setCursor(0,1);
    lcd.print(F("in devaluing my "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("feelings, in not"));
    lcd.setCursor(0,1);
    lcd.print(F("listening to me."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("And in assuming "));
    lcd.setCursor(0,1);
    lcd.print(F(" that because a "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("thing has always"));
    lcd.setCursor(0,1);
    lcd.print(F(" been a certain "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("way inside, that"));
    lcd.setCursor(0,1);
    lcd.print(F(" it will always "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" be that way... "));
    lcd.setCursor(0,1);
    lcd.print(F(" Things change. "));
    Serial.println(F("   blahblah   "));
    delay(2000);
    break;
    
    case 6:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I tried bulimia,"));
    lcd.setCursor(0,1);
    lcd.print(F(" too, like some "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("of my friends at"));
    lcd.setCursor(0,1);
    lcd.print(F(" the time. The  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" most memorable "));
    lcd.setCursor(0,1);
    lcd.print(F(" time was on my "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("18th birthday at"));
    lcd.setCursor(0,1);
    lcd.print(F("my parents house"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" I ran outside  "));
    lcd.setCursor(0,1);
    lcd.print(F("  after eating  "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  cake with my  "));
    lcd.setCursor(0,1);
    lcd.print(F("   parents.     "));
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
