#include <Adafruit_CircuitPlayground.h>

// Pin for the conductive thread (analog input)
const int touchCloth = A7;  // Analog pin connected to the conductive nylon
const int touchThreadLeft = A1;
const int touchThreadRight = A2;
const int touchThreadMid = A3; 
const int buzzer = 0; // Onboard buzzer pin (A4 on CPX)

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
  pinMode(buzzer, OUTPUT);

  // Start Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the value from the conductive thread connected to the analog pin
  int touchClothVal = analogRead(touchCloth);
  int touchThreadLeftVal = analogRead(touchThreadLeft);
  int touchThreadMidVal = analogRead(touchThreadMid);
  int touchThreadRightVal = analogRead(touchThreadRight);

  // Print the touch value to the Serial Monitor for debugging
  Serial.println("Cloth: ");
  Serial.println(touchClothVal);
  Serial.println("Thread Left: " && touchThreadLeftVal);
  Serial.println("Thread Middle: " && touchThreadMidVal);
  Serial.println("Thread Right: " && touchThreadRightVal);

  // Map the touch value to a frequency (musical note)
  int noteFrequency = 0;

  // CLOTH Check the touch value range and assign the corresponding musical note
  if (touchClothVal >= 500) {
    noteFrequency = G4;  // G note (784 Hz)
  }

  //THREAD LEFT  Check the touch value range and assign the corresponding musical note
  if (touchThreadLeftVal >= 500) {
    noteFrequency = C4;  // C note (523 Hz)
  }

  //THREAD MIDDLE  Check the touch value range and assign the corresponding musical note
  if (touchThreadMidVal >= 500) {
    noteFrequency = D4;  // D note (587 Hz)
  }

  //THREAD RIGHT  Check the touch value range and assign the corresponding musical note
  if (touchThreadRightVal >= 500) {
    noteFrequency = E4;  // E note (659 Hz)
  }

  // If the touch value falls within one of the ranges, produce the note
  if (noteFrequency != 0) {
    tone(buzzer, noteFrequency);  // Produce the sound for the mapped note
  } else {
    noTone(buzzer);  // Stop the buzzer if no valid touch is detected
  }

  // Map the touch value to a brightness level for the LED (optional)
  int brightness = map(touchCloth, 0, maxTouchValue, 0, 255);  // Map touch value to LED brightness
  CircuitPlayground.setPixelColor(0, brightness, 0, 200);  // Red LED with brightness mapped to touch value

  // Small delay to prevent jitter
  delay(50);
}
