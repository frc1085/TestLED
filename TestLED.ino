
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 30

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 5
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

// Define a pattern
#define PATTERN_COUNT 3
int pattern_start = 0;
CRGB pattern[PATTERN_COUNT] = { CRGB::Aqua, CRGB::White, CRGB::Black };

void setup() { 
      // Uncomment/edit one of the following lines for your leds arrangement.
       FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      //FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
Serial.begin(9600);
      
      
      // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 
  animate();
}

void animate() {
  // Loop over the pattern starting at the pattern offset
  int j = pattern_start;
  for (int i=0;i<NUM_LEDS;i++) {
    // Set the current light color
    leds[i] = pattern[j++];

    // If j went over the end of the pattern, set it back to zero
    if (j == PATTERN_COUNT) {
      j = 0;
    }
  }

  // Show and wait
  FastLED.show();
  delay(1000);

  pattern_start++;

  // If pattern_start went over the end of the pattern, set it back to zero
  if (pattern_start == PATTERN_COUNT) {
    pattern_start = 0;
  }
}

void old_code() {
  // Turn the LED on, then pause
  /*leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(1000);*/

  for(int i=0;i<NUM_LEDS;i++){
    leds[i] = CRGB::White;
  
  }
  Serial.print("White");
   FastLED.show();
  delay(1000);
    for(int i=0;i<NUM_LEDS;i++){
    leds[i] = CRGB::Black;
   
  }
  Serial.print("Black");
   FastLED.show();
  delay(1000);
 
 /* for(int i=0;i<4;i++){
    for(int j=0;j<NUM_LEDS-3;j+=4){
      leds[j]=CRGB::Red;
      leds[j+1]=leds[j+2]=leds[j+3]=CRGB::Black;
    }
    FastLED.show();
    delay(1000);
    for(int j=0;j<NUM_LEDS-3;j+=4){
      leds[j+1]=CRGB::Red;
      leds[j]=leds[j+2]=leds[j+3]=CRGB::Black;
    }
    FastLED.show();
    delay(1000);
    for(int j=0;j<NUM_LEDS-3;j+=4){
      leds[j+2]=CRGB::Red;
      leds[j]=leds[j+1]=leds[j+3]=CRGB::Black;
    }
    FastLED.show();
    delay(1000);
    for(int j=0;j<NUM_LEDS-3;j+=4){
      leds[j+3]=CRGB::Red;
      leds[j]=leds[j+1]=leds[j+2]=CRGB::Black;
    }
    FastLED.show();
    delay(1000);
  }*/
}

