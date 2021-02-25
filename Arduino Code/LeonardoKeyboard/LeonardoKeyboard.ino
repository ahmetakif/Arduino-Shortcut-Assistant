#include "Keyboard.h"

// For buttons
const int buttona = 4;  // Low
const int buttonb = 2;  // Low
const int buttonc = A0; // High
const int buttond = A5; // High
const int rotarys = 3;  // Low
int buttonaState;
int buttonbState;
int buttoncState;
int buttondState;
int rotarysState;
int previousButtonaState = HIGH;
int previousButtonbState = HIGH;
int previousButtoncState = LOW;
int previousButtondState = LOW;
int previousRotarysState = HIGH;

// For the rotary encoder
int encoder0PinA = 13;
int encoder0PinB = 12;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;

void setup() {
  pinMode(buttona, INPUT);
  pinMode(buttonb, INPUT);
  pinMode(buttonc, INPUT);
  pinMode(buttond, INPUT);
  pinMode(rotarys, INPUT);
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  Keyboard.begin();
}

void loop() {
  buttonaState = digitalRead(buttona);
  buttonbState = digitalRead(buttonb);
  buttoncState = digitalRead(buttonc);
  buttondState = digitalRead(buttond);
  rotarysState = digitalRead(rotarys);

  n = digitalRead(encoder0PinA);
  if ((encoder0PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos--;
      Keyboard.press(KEY_PAGE_UP);
      delay(5);
      Keyboard.releaseAll();
      delay(301);
    } else {
      encoder0Pos++;
      Keyboard.press(KEY_PAGE_DOWN);
      delay(5);
      Keyboard.releaseAll();
      delay(301);
    }
  }
  encoder0PinALast = n;

  if ((buttonaState != previousButtonaState) && (buttonaState == LOW)) {
    Keyboard.press(KEY_LEFT_CTRL);
    delay(5);
    Keyboard.press(KEY_LEFT_SHIFT);
    delay(5);
    Keyboard.press(KEY_ESC);
    delay(5);
    Keyboard.releaseAll();
  }
  if ((buttonbState != previousButtonbState) && (buttonbState == LOW)) {
    Keyboard.press(KEY_LEFT_CTRL);
    delay(5);
    Keyboard.press(116);
    delay(5);
    Keyboard.releaseAll();
  }
  if ((buttoncState != previousButtoncState) && (buttoncState == HIGH)) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(5);
    Keyboard.press(108);
    delay(5);
    Keyboard.releaseAll();
  }
  if ((buttondState != previousButtondState) && (buttondState == HIGH)) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(5);
    Keyboard.press(KEY_LEFT_CTRL);
    delay(5);
    Keyboard.press(100);
    delay(5);
    Keyboard.releaseAll();
  }
  if ((rotarysState != previousRotarysState) && (rotarysState == LOW)) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(5);
    Keyboard.press(105);
    delay(5);
    Keyboard.releaseAll();
  }
  previousButtonaState = buttonaState;
  previousButtonbState = buttonbState;
  previousButtoncState = buttoncState;
  previousButtondState = buttondState;
  previousRotarysState = rotarysState;
}
