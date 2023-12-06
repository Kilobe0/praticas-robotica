// Este código utiliza um sensor ultrassônico e um display LCD para exibir a distância medida e acionar LEDs com base na proximidade de um objeto. Dependendo da distância detectada, diferentes mensagens e LEDs são ativados:
// Dependendo da distância detectada, diferentes mensagens e LEDs são ativados:
//
// Muito Perto (< 5 cm): O LCD mostra "BATEU" e acende o LED vermelho.
// Perto (< 50 cm, mas >= 5 cm): O LCD exibe "VAI BATER" e acende o LED vermelho.
// Moderadamente Perto (< 100 cm, mas >= 50 cm): O LCD mostra "CUIDADO" e acende o LED amarelo.
// Longe (>= 100 cm): O LCD exibe "SEGURO" e acende o LED verde.

#include <HCSR04.h>
#include <LiquidCrystal_I2C.h>

#define ledVermelho 4
#define ledAmarelo 5
#define ledVerde 12

LiquidCrystal_I2C lcd(0x27, 16, 2);
HCSR04 hc(2, 3);
int distancia;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  layout();
  distancia = hc.dist();
  if (distancia < 5) {
    sensor("BATEU", 1, 1, 1, 6, 1);
  } else if (distancia < 50) {
    sensor("VAI BATER", 1, 0, 0, 4, 1);
  } else if (distancia < 100) {
    sensor("CUIDADO", 0, 1, 0, 4, 1);
  } else {
    sensor("SEGURO", 0, 0, 1, 5, 1);
  }
}

void sensor(String msg, int vermelho, int amarelo, int verde, int coluna, int linha) {
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(coluna, linha);
  lcd.print(msg);
  digitalWrite(ledVermelho, vermelho);
  digitalWrite(ledAmarelo, amarelo);
  digitalWrite(ledVerde, verde);
}

void layout() {
  lcd.setCursor(1, 0);
  lcd.print("Distancia: ");
  if (distancia < 100) {
    if (distancia < 10) {
      lcd.setCursor(11, 0);
      lcd.print(0);
      lcd.setCursor(12, 0);
      lcd.print(0);
      lcd.setCursor(13, 0);
      lcd.print(distancia);
    } else {
      lcd.setCursor(11, 0);
      lcd.print(0);
      lcd.setCursor(12, 0);
      lcd.print(distancia);
    }
  } else {
    lcd.setCursor(11, 0);
    lcd.print(distancia);
  }
  lcd.setCursor(14, 0);
  lcd.print("m");
}