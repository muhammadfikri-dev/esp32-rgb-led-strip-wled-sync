#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 18
#define PIN_MIC 36

CRGB leds[NUM_LEDS];

void setup() {
 FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
 FastLED.setBrightness(120);
}

void loop() {
 int audioSample = analogRead(PIN_MIC);
 int activeLeds = map(audioSample, 1500, 3000, 0, NUM_LEDS);
 activeLeds = constrain(activeLeds, 0, NUM_LEDS);

 for (int i = 0; i < NUM_LEDS; i++) {
 if (i < activeLeds) {
 leds[i] = CHSV(map(i, 0, NUM_LEDS, 0, 255), 255, 255);
 } else {
 leds[i] = CRGB::Black;
 }
 }
 FastLED.show();
 delay(20);
}