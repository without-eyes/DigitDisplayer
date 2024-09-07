// constants
const int pinCount = 7;
const int numberCount = 10;
const int maxNumber = 9;
const int minNumber = 0;
const int maxBrightness = 255;
const int minBrightness = 0;
const int brightnessChangeStep = 50;

// pins
//                          A  B  C  D  E  F  G
const int pins[pinCount] = {7, 6, 4, 3, 2, 8, 9};
const int increaseButtonPin = 10;
const int decreaseButtonPin = 11;
const int brightnessButtonPin = 12;
const int brightnessPin = 5;

// 7-segment display patterns for numbers 0-9
const int numbers[numberCount][pinCount] = {
// A  B  C  D  E  F  G
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

// variables
int currentNumber = 0;
int currentBrightness = maxBrightness;
bool isButtonsPressed = false;
bool isBrightnessIncreasing = true;

void setup() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(increaseButtonPin, INPUT_PULLUP);
  pinMode(decreaseButtonPin, INPUT_PULLUP);
  pinMode(brightnessButtonPin, INPUT_PULLUP);
  pinMode(brightnessPin, OUTPUT);
}

void loop() {
  handleNumberChange();
  handleBrightnessChange();
  displayNumber();
  delay(100);
}

void handleNumberChange() {
  if (isButtonPressed(increaseButtonPin) && !isButtonsPressed) {
    currentNumber = constrain(currentNumber + 1, minNumber, maxNumber);
    isButtonsPressed = true;
  } else if (isButtonPressed(decreaseButtonPin) && !isButtonsPressed) {
    currentNumber = constrain(currentNumber - 1, minNumber, maxNumber);
    isButtonsPressed = true;
  } else if (areButtonsReleased()) {
    isButtonsPressed = false;
  }
}

void handleBrightnessChange() {
  if (isButtonPressed(brightnessButtonPin) && !isButtonsPressed) {
    currentBrightness = isBrightnessIncreasing ? currentBrightness + brightnessChangeStep : currentBrightness - brightnessChangeStep;
    currentBrightness = constrain(currentBrightness, minBrightness, maxBrightness);
    if (currentBrightness == maxBrightness) isBrightnessIncreasing = false;
    else if (currentBrightness == minBrightness) isBrightnessIncreasing = true;
    isButtonsPressed = true;
  }
  analogWrite(brightnessPin, currentBrightness);
}

void displayNumber() {
  for (int i = 0; i < pinCount; i++) {
    digitalWrite(pins[i], numbers[currentNumber][i]);
  }
}

bool isButtonPressed(int pin) {
  return !digitalRead(pin);
}

bool areButtonsReleased() {
  return digitalRead(increaseButtonPin) && digitalRead(decreaseButtonPin) && digitalRead(brightnessButtonPin);
}
