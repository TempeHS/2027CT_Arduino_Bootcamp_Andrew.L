/*
  Author: Andrew Yong Ly
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Student Notes:
  1. Make sure you include a copy of your schematic
  2. Students should use either the button or potentiometer in an unconventional way

  3. Suggested Grove ports: Button D4, Potentiometer A0, LED D6, Light sensor A3
*/

const int BUTTON_PIN = 4;  // Grove Button on D4
const int LED_PIN = 6;     // Grove LED on D6

int lightOn = 0; // 0 = light off, 1 = light on
int lastButtonState = LOW;
unsigned long pressStartTime = 0;
bool holding = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && lastButtonState == LOW) {
    // button just got pressed, start the timer
    pressStartTime = millis();
    holding = true;
  }

  if (buttonState == HIGH && holding) {
    // still holding it down, check how long for
    if (millis() - pressStartTime >= 2000) {
      lightOn = !lightOn; // flip the light on/off
      holding = false;    // stop it flipping again while still held down
    }
  }

  if (buttonState == LOW) {
    holding = false; // button let go, reset for next time
  }

  digitalWrite(LED_PIN, lightOn ? HIGH : LOW);

  lastButtonState = buttonState;
}
