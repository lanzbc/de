#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

#define PIN        6
#define NUMPIXELS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100

void setup() { 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
}
void loop() {
  pixels.clear(); 
  for(int i=0; i<NUMPIXELS; i++) {     
    pixels.setPixelColor(1, pixels.Color(0, 10, 0));
    pixels.show();
    delay(DELAYVAL); 
  }
}
