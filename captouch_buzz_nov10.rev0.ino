#include <Adafruit_CircuitPlayground.h>

// Pin for the conductive thread (analog input)
const int touchPin = A1;  // Analog pin connected to the conductive thread
const int buzzerPin = 0; // Onboard buzzer pin (A4 on CPX)

const int touchThreshold = 400;  // Start detecting from touch value 400 (lower threshold)
const int maxTouchValue = 1023;  // Max value from analogRead

// Frequencies for musical notes (in Hz)
const int AFour = 440;
const int B4 = 466;
const int C4 = 523;
const int D4 = 587;
const int E4 = 659;
const int F4 = 698;
const int G4 = 784;

void setup() {
  // Initialize the Circuit Playground library
  CircuitPlayground.begin();

  // Initialize the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Start Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the value from the conductive thread connected to the analog pin
  int touchValue = analogRead(touchPin);

  // Print the touch value to the Serial Monitor for debugging
  Serial.println(touchValue);

  // Map the touch value to a frequency (musical note)
  int noteFrequency = 0;

  // Check the touch value range and assign the corresponding musical note
  if (touchValue >= 400 && touchValue <= 500) {
    noteFrequency = AFour;  // A note (440 Hz)
  } 
  else if (touchValue >= 501 && touchValue <= 600) {
    noteFrequency = B4;  // B note (466.16 Hz)
  } 
  else if (touchValue >= 601 && touchValue <= 700) {
    noteFrequency = C4;  // C note (523.25 Hz)
  } 
  else if (touchValue >= 701 && touchValue <= 800) {
    noteFrequency = D4;  // D note (587.33 Hz)
  } 
  else if (touchValue >= 801 && touchValue <= 900) {
    noteFrequency = E4;  // E note (659.26 Hz)
  } 
  else if (touchValue >= 901 && touchValue <= 950) {
    noteFrequency = F4;  // F note (698.46 Hz)
  } 
  else if (touchValue >= 951 && touchValue <= maxTouchValue) {
    noteFrequency = G4;  // G note (783.99 Hz)
  }

  // If the touch value falls within one of the ranges, produce the note
  if (noteFrequency != 0) {
    tone(buzzerPin, noteFrequency);  // Produce the sound for the mapped note
  } else {
    noTone(buzzerPin);  // Stop the buzzer if no valid touch is detected
  }

  // Map the touch value to a brightness level for the LED (optional)
  int brightness = map(touchValue, 0, maxTouchValue, 0, 255);  // Map touch value to LED brightness
  CircuitPlayground.setPixelColor(0, brightness, 0, 0);  // Red LED with brightness mapped to touch value

  // Small delay to prevent jitter
  delay(50);
}
