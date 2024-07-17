#include <LedControl.h>

// Pins for the LED matrix
int DIN = 12;
int CS = 11;
int CLK = 10;

// Create a LedControl instance
LedControl lc = LedControl(DIN, CLK, CS, 1);

// Mouth closed pattern
byte mouthClosed[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00111100,
  B00000000,
  B00000000,
  B00000000
};

// Mouth open pattern
byte mouthOpen[8] = {
  B00000000,
  B00000000,
  B01111110,
  B01111110,
  B01111110,
  B01111110,
  B00000000,
  B00000000
};

void setup() {
  // Initialize the LED matrix
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // Display mouth closed
  displayPattern(mouthClosed);
  delay(500);
  
  // Display mouth open
  displayPattern(mouthOpen);
  delay(500);
}

void displayPattern(byte pattern[8]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, pattern[i]);
  }
}