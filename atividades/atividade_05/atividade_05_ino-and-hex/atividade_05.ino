#include <Arduino.h>

const byte ledPin = 7;
const byte interruptPin = 2;
volatile byte state = LOW;
int ligado = 2000;
int desligado = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(ligado);
  digitalWrite(ledPin, LOW);
  delay(desligado);
}
void blink() {
  state = !state;

  if(state == LOW){
    ligado = 2000;
    desligado = 1000;
  } else {
    ligado = 5000;
    desligado = 25000;
  }
}

