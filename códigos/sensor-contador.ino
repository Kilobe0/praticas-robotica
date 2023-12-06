// Este código controla dois LEDs (um amarelo e um vermelho) e lê a entrada de um sensor e um botão. 
// Quando o botão é pressionado, o LED vermelho acende. Enquanto o LED vermelho está aceso, o programa verifica o sensor. 
// Se o sensor detecta algo, o LED amarelo pisca três vezes e o número de detecções é contabilizado e exibido no monitor serial. 
// O LED vermelho se apaga ao pressionar o botão novamente, e o contador de detecções é reiniciado.

#define sens 8
#define botao 11
#define ledAmarelo 12
#define ledVermelho 13

void setup() {
  Serial.begin(9600);
  pinMode(botao, INPUT);
  pinMode(sens, INPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

int valor;
int bot;
bool ligado = false;
int cont = 0;

void pisca() {
  digitalWrite(ledAmarelo, HIGH);
  delay(500);
  digitalWrite(ledAmarelo, LOW);
  delay(500);
}

void loop() {
  bot = digitalRead(botao);  
  valor = digitalRead(sens);
  
  if(bot == HIGH){
    ligado = true;
    digitalWrite(ledVermelho, HIGH);
    while(ligado == true) {
      valor = digitalRead(sens);
      if(valor == HIGH){
        cont++;      
        for(int i=0;i<3;i++){
          digitalWrite(ledAmarelo, HIGH);
          delay(500);
          digitalWrite(ledAmarelo, LOW);
          delay(500);
        }
        Serial.print("DETECCAO! TOTAL: ");
        Serial.println(cont); 
      }
      bot = digitalRead(botao);
      if(bot == HIGH){
        ligado = false;
        digitalWrite(ledVermelho, LOW);
        cont = 0;
        delay(500);
      }
    }
  }
}