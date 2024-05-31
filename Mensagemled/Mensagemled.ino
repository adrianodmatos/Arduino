#include <LiquidCrystal.h>

// Define os pinos do LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Define os pinos dos botões
const int buttonPin1 = 6;
const int buttonPin2 = 7;
const int buttonPin3 = 8;
// Variável para armazenar a mensagem atual
int mensagem;
// Define uma mensagem do tipo struct
struct Message {
  String text;
  String type;
};
//Aqui está nossa matriz de mensagens
Message messages[3] = {
  {"Bateria descarregando", "Alerta"},
  {"Chuva prevista", "Informe"},
  {"Parametro incorreto", "Erro"}
};

// Função para exibir uma mensagem no LCD
void displayMessage(int index) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(messages[index].type + ":");
  lcd.setCursor(0, 1);
  lcd.print(messages[index].text);
}

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2);
  // Aqui os botões de acionamento são adicionados
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  
  // A mensagem se botão 1 for pressionado
  if (digitalRead(buttonPin1) == LOW) {
    mensagem = 0;
    displayMessage(mensagem);
    delay(3000); //Tempo de exibição da mensagem
  }

  // A mensagem se botão 2 for pressionado
  if (digitalRead(buttonPin2) == LOW) {
    mensagem = 1;
    displayMessage(mensagem);
    delay(3000); //Tempo de exibição da mensagem
  }

  // A mensagem se botão 3 for pressionado
  if (digitalRead(buttonPin3) == LOW) {
    mensagem = 2;
    displayMessage(mensagem);
    delay(3000); //Tempo de exibição da mensagem
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Aperte um botao");
    delay(100); // Tempo de exibição da mensagem
  }
}
