I.	Apresentação do código-fonte (colorido):
int semaforo = 0;//a variável que vai receber os valores do sensor

void setup()
{
  pinMode(3, OUTPUT);//led vermelho: saída digital
  pinMode(4, OUTPUT);//led amarelo: saída digital
  pinMode(5, OUTPUT);//led verde: saída digital
  pinMode(2, INPUT);//sensor de presença: entrada digital
}

void loop()
{
  semaforo = digitalRead(2);
  //o digital read vai ler o sinal enviado ou não pelo sensor
  //a nossa variável vai receber esse valor
  
  if(semaforo == 0)//caso o sensor não envie nenhum sinal, a variável terá valor de 0 e o If será true
 {digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(1000);
    
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1000);
    
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(1000); }
  //como não houve detecção de presença, as luzes do semaforo ficarão acesas pelo mesmo periodo de tempo
  
  else//caso o sensor de presença envie um sinal, o semaforo vai funcionar, porém o led verde ficará mais tempo ligado  
  {digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(7000);
  //o led verde ficará aceso por 7 segundos, em referência ao último número do meu RU
  //RU: 4024057
    
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1000);
    
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(1000);}
   
  //após finalizar o código, ele faz o loop novamente para verificar o sinal do sensor
  delay(100);
}
