// Esse código usa um display LCD para criar uma sequência numérica crescente e decrescente. 
// Inicialmente, ele exibe números de 1 a 9, aumentando a quantidade de dígitos a cada passo (por exemplo, 22, 333, etc.), 
// e depois faz o inverso, diminuindo a quantidade de dígitos do 9 para o 1. 
// Em cada passo, a linha superior do LCD mostra a sequência anterior, enquanto a linha inferior mostra a sequência atual,
// com um breve intervalo entre as mudanças.
// Exemplo de saída:
// -----------
// Linha 1: 1
// Linha 2: 22
// -----------
// Linha 1: 22
// Linha 2: 333
// ------------

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 5, 4, 3, 2, 1);

void setup() {
  lcd.begin(16, 2);
}

String atual = "";
String antigo = "1";

void loop() {
  for (int i = 2; i <= 9; i++) {
    lcd.clear();
    for (int j = 1; j <= i; j++) {
      atual = atual + String(i);
    }
    lcd.setCursor(0, 0);
    lcd.print(antigo);
    delay(500);
    lcd.setCursor(0, 1);
    lcd.print(atual);
    delay(500);

    antigo = atual;
    atual = "";
  }

  atual = "";
  antigo = "999999999";
  for (int i = 8; i >= 1; i--) {
    lcd.clear();
    for (int j = i; j >= 1; j--) {
      atual = atual + String(i);
    }
    lcd.setCursor(0, 0);
    lcd.print(antigo);
    delay(500);
    lcd.setCursor(0, 1);
    lcd.print(atual);
    delay(500);

    antigo = atual;
    atual = "";
  }
}