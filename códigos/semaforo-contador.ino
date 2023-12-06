// Simula um sistema de semáforo com um recurso adicional de display de contagem regressiva.
// Inclui um sinal de pedestres e um display de 7 segmentos para contar o tempo restante do sinal vermelho.
// O sistema responde ao pressionamento de um botão, simulando um pedestre solicitando para atravessar a rua.

#include "SevSeg.h"
SevSeg setSeg;

int ledVerde = 0;
int ledAmarelo = 1;
int ledVermelho = 2;
int botao = 3;
int ledPvermelho = 4;
int ledPverde = 5;

int a = 6;
int b = 7;
int c = 8;
int d = 9;
int e = 10;
int f = 11;
int g = 12;
int dp = 13;

void setup() {
  byte num = 1;
  byte pinos[] = {};
  byte pinosDisplay[] = { a, b, c, d, e, f, g, dp };
  setSeg.begin(COMMON_CATHODE, num, pinos, pinosDisplay, true);
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(ledPverde, OUTPUT);
  pinMode(ledPvermelho, OUTPUT);
}

int bot1 = 0;

void loop() {
  digitalWrite(ledPverde, LOW);
  digitalWrite(ledPvermelho, HIGH);
  digitalWrite(ledVerde, HIGH);
  bot1 = digitalRead(botao);
  delay(100);
  
  if (bot1 == 1) {
    digitalWrite(ledPvermelho, LOW);
    digitalWrite(ledVerde, LOW);
    delay(200);
    digitalWrite(ledAmarelo, HIGH);
    delay(2000);
    digitalWrite(ledAmarelo, LOW);
    delay(200);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledPverde, HIGH);
    for (int i = 9; i > 2; i--) {
      setSeg.setNumber(i);
      setSeg.refreshDisplay();
      delay(1000);
    }
    setSeg.setNumber(2);
    setSeg.refreshDisplay();
    digitalWrite(ledPverde, LOW);
    delay(500);
    digitalWrite(ledPverde, HIGH);    
    delay(500);
    setSeg.setNumber(1);
    setSeg.refreshDisplay();
    digitalWrite(ledPverde, LOW);
    delay(500);
    digitalWrite(ledPverde, HIGH);   
    delay(500);

    setSeg.setNumber(0);
    setSeg.refreshDisplay();
    digitalWrite(ledPverde, HIGH);
    delay(500);
    digitalWrite(ledPverde, LOW);   
    delay(500);

    digitalWrite(ledVermelho, LOW);
  }
}
