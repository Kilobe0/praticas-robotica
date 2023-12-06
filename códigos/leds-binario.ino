// Este código define os pinos dos LEDs e inicializa a comunicação serial.
// Em seguida, define variáveis para cada bit e resto, e cria funções para resetar os LEDs e ligar os LEDs de acordo com o valor binário.
// No loop principal, o código itera de 0 a 15, reseta os LEDs e calcula os valores binários para os LEDs com base no valor de i.

#define led1 5
#define led2 4
#define led3 3
#define led4 2

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

int bit1;
int bit2;
int bit3;
int bit4;
int resto1;
int resto2;
int resto3;

void reset() {
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(led4, 0);
}

void ligarBinario(int bit1, int bit2, int bit3, int bit4) {
  digitalWrite(led1, bit1);
  digitalWrite(led2, bit2);
  digitalWrite(led3, bit3);
  digitalWrite(led4, bit4);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    reset();

    bit1 = i % 2;
    resto1 = i / 2;
    bit2 = resto1 % 2;
    resto2 = resto1 / 2;
    bit3 = resto2 % 2;
    resto3 = resto2 / 2;
    bit4 = resto3 % 2;

    ligarBinario(bit1, bit2, bit3, bit4);
    delay(1000);
  }
}
