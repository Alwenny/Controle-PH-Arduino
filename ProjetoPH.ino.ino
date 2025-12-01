#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

const int motorSpeed = 19;
const int motorSteps = 512;

const int pinoPH = A0;
const int pinoLEDAcido = 7;
const int pinoLEDAlcalino = 6;
const int pinoLEDNeutro1 = 5;
const int pinoLEDNeutro2 = 4;

const int valorNeutroBaixo = 660;
const int valorNeutroAlto = 720;

void setup() {
  Serial.begin(9600);

  myStepper.setSpeed(motorSpeed);

  pinMode(pinoLEDAcido, OUTPUT);
  pinMode(pinoLEDAlcalino, OUTPUT);
  pinMode(pinoLEDNeutro1, OUTPUT);
  pinMode(pinoLEDNeutro2, OUTPUT);

  digitalWrite(pinoLEDAcido, LOW);
  digitalWrite(pinoLEDAlcalino, LOW);
  digitalWrite(pinoLEDNeutro1, LOW);
  digitalWrite(pinoLEDNeutro2, LOW);

  Serial.println("Sistema de Controlo de pH e Motor iniciado.");
}

void loop() {
  int valorAnalogico = analogRead(pinoPH);

  Serial.print("Valor Bruto: ");
  Serial.print(valorAnalogico);

  if (valorAnalogico < valorNeutroBaixo) {
    digitalWrite(pinoLEDAcido, HIGH);
    digitalWrite(pinoLEDAlcalino, LOW);
    digitalWrite(pinoLEDNeutro1, LOW);
    digitalWrite(pinoLEDNeutro2, LOW);

    Serial.println("  << ÁCIDO - Motor PARADO >>");
    delay(500);

  } else if (valorAnalogico > valorNeutroAlto) {
    digitalWrite(pinoLEDAcido, LOW);
    digitalWrite(pinoLEDAlcalino, HIGH);
    digitalWrite(pinoLEDNeutro1, LOW);
    digitalWrite(pinoLEDNeutro2, LOW);

    Serial.println("  << ALCALINO - Motor PARADO >>");
    delay(500);

  } else {
    digitalWrite(pinoLEDAcido, LOW);
    digitalWrite(pinoLEDAlcalino, LOW);
    digitalWrite(pinoLEDNeutro1, HIGH);
    digitalWrite(pinoLEDNeutro2, HIGH);

    Serial.println("  (Neutro - Motor a RODAR...)");

    myStepper.step(-motorSteps);
  }
}