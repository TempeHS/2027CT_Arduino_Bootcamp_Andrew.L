class Button {
  private:
    int pin;
  public:
    Button(int buttonPin) {   // store the pin
      pin = buttonPin;
    }
    void begin() {            // pinMode INPUT
      pinMode(pin, INPUT);
    }
    bool isPressed() {        // true while held (Grove button reads HIGH pressed)
      return digitalRead(pin) == HIGH;
    }
};

const int BUTTON_PIN = 4;
const int LED1_PIN = 5;
const int LED2_PIN = 6;

Button button(BUTTON_PIN);
bool led1On = true;

void setup() {
  button.begin();
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  if (button.isPressed()) {
    digitalWrite(LED1_PIN, led1On ? HIGH : LOW);
    digitalWrite(LED2_PIN, led1On ? LOW : HIGH);
    led1On = !led1On;
    delay(200);
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }
}
