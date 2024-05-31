float Temperatura[40];//Vetor onde serão armazenadas as informações

float lertemp(){
  float tensao = analogRead(A0) * 5.0/1023.0;
  float temperatura = tensao * 100.0;
  return temperatura;} //Função que vai executar a leitura da temperatura

      
void setup(){
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}
  
void loop(){
 float Registro;
 int cont=0;
 
  for(cont;cont<40;cont++){
    Temperatura[cont] = lertemp();
    Serial.print("Registro de temperatura num ");
    Serial.println(cont+1);
    Serial.println(Temperatura[cont]);
    delay(50000);}//O for realiza a operação até chegar em 40 registros,
                  //A cada posição da variável cont é adicionada a leitura de temperatura
                  //Essa leitura é realizada a cada 5 minutos, conforme o penultimo número do meu RU
                  //Após 40 registros o número é reiniciado  
}

