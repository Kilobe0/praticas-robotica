// Cronômetro exibido em LCD controlado por botões e LEDs que indicam a passagem do tempo.
// A Linha 1 exibe o título "Cronometro", enquanto a Linha 2 mostra o tempo atual do cronômetro em horas, minutos e segundos.
// O código também controla os LEDs de acordo com a duração:
// O LED verde acende para menos de 1 minuto, o LED amarelo acende entre 1 e 2 minutos, e o LED vermelho acende após 2 minutos.

#include "LiquidCrystal_I2C.h"

#define endereco 0x27
#define colunas 16
#define linhas 2

int ledVerde = 2;
int ledAmarelo = 3;
int ledVermelho = 4;
int botao1 = 7;
int botao2 = 8;

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

int segundos = 0;
int minutos = 0;
int horas = 0;

void setup() {
  lcd.init();

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

  lcd.setCursor(3, 0);
  lcd.print("Cronometro");
  lcd.setCursor(4, 1);
  lcd.print("00");
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(7, 1);
  lcd.print("00");
  lcd.setCursor(9, 1);
  lcd.print(":");
  lcd.setCursor(10, 1);
  lcd.print("00");
  lcd.backlight();
}

bool ativo = false;
void loop() {
  if (digitalRead(botao1)) {
    ativo = true;
  }

  if (digitalRead(botao1) && ativo) {
    ativo = false;
  }

  if (digitalRead(botao2)) {
    ativo = false;
    segundos = 0;
    minutos = 0;
    horas = 0;
    lcd.setCursor(3, 0);
    lcd.print("Cronometro");
    lcd.setCursor(4, 1);
    lcd.print("00");
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(7, 1);
    lcd.print("00");
    lcd.setCursor(9, 1);
    lcd.print(":");
    lcd.setCursor(10, 1);
    lcd.print("00");
    lcd.backlight();
  }

  if (ativo) {
    cronometro();
    led();
  }
}

void cronometro() {
  segundos++;
  atualizaSec();
  layout();
  delay(100);
}

void led() {
  if (minutos < 1) {
    digitalWrite(ledVerde, HIGH);
  } else if (minutos < 2) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
  }
}

void layout() {
  if (segundos < 10) {
    lcd.setCursor(10, 1);
    lcd.print("0");
    lcd.print(segundos);
  } else {
    lcd.setCursor(10, 1);
    lcd.print(segundos);
  }
  if (minutos < 10) {
    lcd.setCursor(7, 1);
    lcd.print("0");
    lcd.print(minutos);
  } else {
    lcd.setCursor(7, 1);
    lcd.print(minutos);
  }
  if (horas < 10) {
    lcd.setCursor(4, 1);
    lcd.print("0");
    lcd.print(horas);
  } else {
    lcd.setCursor(4, 1);
    lcd.print(horas);
  }
}

void atualizaSec() {
  if (segundos == 60) {
    segundos = 0;
    minutos++;
  }
  if (minutos == 60) {
    minutos = 0;
    horas++;
  }
  if (horas == 24) {
    segundos = 0;
    minutos = 0;
    horas = 0;
  }
}
