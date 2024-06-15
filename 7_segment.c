/*
    Project name : Seven Segment Display
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-seven-segment-display
*/

// Pin definitions for 7-segment display segments (a-g) and dot
const int segments[] = {2, 3, 4, 5, 6, 7, 8, 9};

// Common cathode 7-segment display digit patterns (0-9)
const byte digitPatterns[10] = {
  B11111100,   // 0
  B01100000,   // 1
  B11011010,   // 2
  B11110010,   // 3
  B01100110,   // 4
  B10110110,   // 5
  B10111110,   // 6
  B11100000,   // 7
  B11111110,   // 8
  B11110110    // 9
};

void setup() {
  // Set all segment pins as OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void loop() {
  // Display numbers 0 to 9 repeatedly
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1000);  // Delay 1 second between each number
  }
}

void displayNumber(int number) {
  if (number >= 0 && number <= 9) {
    byte segmentsToDisplay = digitPatterns[number];
    for (int i = 0; i < 8; i++) {
      digitalWrite(segments[i], bitRead(segmentsToDisplay, i));
    }
  }
}
