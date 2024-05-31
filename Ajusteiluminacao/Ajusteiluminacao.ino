I.	Apresentação do código-fonte (colorido):

// Define os pinos do fotorresistor e do LED
const int ldrPin = A0; // Pino analógico do fotorresistor
const int ledPin = 9;  // Pino digital do LED
const int RU = 40; // Limite de leituras, conforme os dois primeiros dígitos do RU
int *leitura;

// Função para ajustar a intensidade do LED com base na média das leituras
int ajuste(int media) {
  return map(media, 0, 1023, 0, 255);
}

void setup() {
  // Define o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  // Aloca dinamicamente o buffer para armazenar as leituras
  leitura = new int[RU];
}

void loop() {
  // Realiza a leitura atual do fotorresistor
  int valor = analogRead(ldrPin);
  // Adiciona a leitura atual ao buffer de leituras
  adicionarLeitura(valor);
  // Calcula a média das últimas leituras
  int media = calcularMedia();
  // Ajusta a intensidade do LED com base na média das leituras
  int brightness = ajuste(media);
  // Define a intensidade do LED
  analogWrite(ledPin, brightness);
}

// Função para adicionar uma nova leitura ao buffer de leituras
void adicionarLeitura(int iniciar) {
  // Desloca as leituras anteriores para abrir espaço para a nova leitura
  for (int i = RU - 1; i > 0; i--) {
    leitura[i] = leitura[i - 1];
  }
  // Adiciona a nova leitura à primeira posição do buffer
  leitura[0] = iniciar;
}

// Função para calcular a média das últimas leituras do fotorresistor
int calcularMedia() {
  int soma = 0;
  for (int i = 0; i < RU; i++) {
    soma += leitura[i];
  }
  return soma / RU;
}

