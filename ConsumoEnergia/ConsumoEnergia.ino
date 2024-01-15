#include <EmonLib.h>

#define CURRENT_CAL 18.40

int pinoLed = 12;
int pinoSensor = A0;

float valorLido;
float ruidoSensor = 0.4;
float valor;

EnergyMonitor emon1;

void setup() {
  Serial.begin(9600);

  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoLed, LOW);

  emon1.current(pinoSensor, CURRENT_CAL);
}

void loop() {
  emon1.calcVI(17, 500);

  valorLido = emon1.Irms;

  valor = valorLido - ruidoSensor;

  if (valor < 0) {
    valor = 0;
  }

  Serial.print("Corrente medida: ");
  Serial.println(valor);
  delay(500);
}