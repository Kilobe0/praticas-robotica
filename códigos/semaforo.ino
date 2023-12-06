// Este código controla os LEDs verde, amarelo e vermelho com base na leitura de um botão.
// Quando o botão é pressionado:
// O LED verde é desligado, o LED amarelo é ligado por 2 segundos e, em seguida, o LED vermelho é ligado por 10 segundos.

int ledVerde = 3;
int ledAmarelo = 4;
int ledVermelho = 5;
int botao = 10;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botao, INPUT);
}

int bot1 = 0;
void loop() {
  digitalWrite(ledVerde, HIGH);
  bot1 = digitalRead(botao);
  delay(100);

  if (bot1 == 1) {
    digitalWrite(ledVerde, LOW);
    delay(200);
    digitalWrite(ledAmarelo, HIGH);
    delay(2000);
    digitalWrite(ledAmarelo, LOW);
    delay(200);
    digitalWrite(ledVermelho, HIGH);  
    delay(10000);
    digitalWrite(ledVermelho, LOW);
  }
}
