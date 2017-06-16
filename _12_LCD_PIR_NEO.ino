#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define REDLITE 3                 //led RGB pins
#define GREENLITE 5
#define BLUELITE 6

LiquidCrystal lcd(4,8,9,10,11,12);    //lcd data pins

#define pir A3 

#define NUMPIXELS      8       //No of leds in strip
#define STRIP1 A4            //pin for neopixel strip 1
#define STRIP2 A5            //pin for neopixel strip 2

bool toggle_pir = false;
bool pir_timer = false;
uint32_t timer   = 0;

uint8_t brightness = 100;

uint8_t counter;

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS, STRIP1, NEO_RGB + NEO_KHZ800); 
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, STRIP2, NEO_RGB + NEO_KHZ800);

void setup() {
  Serial.begin(19200);
  pinMode(pir,INPUT);
  digitalWrite(pir,LOW);
  strip1.begin();
  strip2.begin();

  lcd.begin(16, 2);
  lcd.print(F(" Welcome, Hello "));
  lcd.setCursor(0,1);

  pinMode(REDLITE, OUTPUT);
  pinMode(GREENLITE, OUTPUT);
  pinMode(BLUELITE, OUTPUT);

  setBacklight(130, 255, 100);

  Serial.println(F("START"));

//  attachInterrupt(digitalPinToInterrupt(pir), solidGold, RISING);
}

void loop() {
  /*
    It is important to note that suddenly, and against all probability, a Sperm Whale had been called into existence, 
    several miles above the surface of an alien planet. Since this isn't a naturally tenable position for a whale, 
    this innocent creature had very little time to come to terms with its identity. This is what it thought, as it fell:
    
    The Whale: Ahhh! Woooh! What's happening? Who am I? Why am I here? What's my purpose in life? What do I mean by who am I? 
    Okay okay, calm down, get a grip now. Ooh, this is an interesting sensation. What is it? Its a sort of tingling in my... 
    well I suppose I better start finding names for things. Lets call it a... tail! Yeah! Tail! And hey, 
    what's this roaring sound, whooshing past what I'm suddenly gonna call my head? Wind! Is that a good name? It'll do. 
    Yeah, this is really exciting. I'm dizzy with anticipation! Or is it the wind? There's an awful lot of that, 
    now isn't it? And what's this thing coming toward me very fast? So big and flat and round, 
    it needs a big wide sounding name like 'Ow', 'Ownge', 'Round', 'Ground'! That's it! Ground! 
    Ha! I wonder if it'll be friends with me? Hello, Ground! [dies]
   */
   if(digitalRead(pir) && pir_timer) {
  timer = millis();
  toggle_pir = !toggle_pir;
  lcdCtrl(random(7));
//    Serial.println("pir");
  }
   neoCtrl(toggle_pir);
//   lcdCtrl(counter);
   pir_timer = ((millis() - timer) >= 16000) ? true : false; 
}

void solidGold() {
  delay(10);
  toggle_pir = !toggle_pir;
  counter = random(7);
}

void neoCtrl(bool _toggle_pir ) {
  int a = 240;
  int b = 30;
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    if (_toggle_pir) { strip1.setPixelColor(i, a, 0x00, b); }// Moderately bright green color. G, R, B
    else { strip1.setPixelColor(i, a, b, 0x00); }
    strip1.setBrightness(25);
    strip1.show(); // This sends the updated pixel color to the hardware.
    
    if (_toggle_pir) { strip2.setPixelColor(i, a, b, 0x00); }// Moderately bright green color. G, R, B
    else { strip2.setPixelColor(i, a, 0x00, b); }
    strip2.setBrightness(25);
    strip2.show(); // This sends the updated pixel color to the hardware.
//    Serial.println(i);
    b += 32;
    a -= 32;
    if ( b > 240){b = 240;}
    if ( a < 30) {a = 30;}
    Serial.print("count = "); Serial.print(_toggle_pir); Serial.print(" a = "); Serial.print(a); Serial.print(" b = "); Serial.println(b);
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
  g=170;
  //Serial.print("R = "); Serial.print(r, DEC);
  //Serial.print(" G = "); Serial.print(g, DEC);
  //Serial.print(" B = "); Serial.println(b, DEC);
  analogWrite(REDLITE, r);
  analogWrite(GREENLITE, g);
  analogWrite(BLUELITE, b);
}

void lcdCtrl(uint8_t _rand) {
  switch (_rand) {
    
    case 0:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Childhood trauma"));
    lcd.setCursor(0,1);
    lcd.print(F("causes lifelong "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  changes to a  "));
    lcd.setCursor(0,1);
    lcd.print(F("persons DNA. One"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("of the genes is "));
    lcd.setCursor(0,1);
    lcd.print(F("  called TPPP.  "));
    Serial.println(F("    parade    "));
    break;
    
    case 1:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Dozens of tests "));
    lcd.setCursor(0,1);
    lcd.print(F("done at Yale, & "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" published. My  "));
    lcd.setCursor(0,1);
    lcd.print(F("hope is that one"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("day doctors can "));
    lcd.setCursor(0,1);
    lcd.print(F("  change that.  "));
    Serial.println(F("    response    "));
    break;
    
    case 2:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Would adults put"));
    lcd.setCursor(0,1);
    lcd.print(F("children in bad "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("  situations if "));
    lcd.setCursor(0,1);
    lcd.print(F(" they knew they "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("were permanently"));
    lcd.setCursor(0,1);
    lcd.print(F(" damaging them? ")); 
    Serial.println(F("    maleable.   ")); 
    break;
    
    case 3:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" People can act "));
    lcd.setCursor(0,1);
    lcd.print(F(" very selfishly."));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("Criminally so..."));
    lcd.setCursor(0,1);
    lcd.print(F("This fact always"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("causes me to be "));
    lcd.setCursor(0,1);
    lcd.print(F(" very, very sad.")); 
    Serial.println(F("other like warriors"));
    break;
    
    case 4:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I want this show"));
    lcd.setCursor(0,1);
    lcd.print(F("to be a platform"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("for awesomeness,"));
    lcd.setCursor(0,1);
    lcd.print(F("a springboard to"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("discussion that "));
    lcd.setCursor(0,1);
    lcd.print(F("leads somewhere.")); 
    Serial.println(F("places at home."));
    break;
    
    case 5:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("If Yale research"));
    lcd.setCursor(0,1);
    lcd.print(F("proves this fact"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" then is anyone "));
    lcd.setCursor(0,1);
    lcd.print(F("searching for a "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F("solution to TPPP"));
    lcd.setCursor(0,1);
    lcd.print(F("to engineer it? "));
    Serial.println(F("   blahblah   "));
    break;
    
    case 6:
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I believe things"));
    lcd.setCursor(0,1);
    lcd.print(F(" can be better. "));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" For me and for "));
    lcd.setCursor(0,1);
    lcd.print(F("others. I really"));
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print(F(" do believe in  "));
    lcd.setCursor(0,1);
    lcd.print(F(" people power.  "));
    Serial.println(F("  many times.  ")); 
    break;
  }
}
