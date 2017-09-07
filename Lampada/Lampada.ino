//Declaração das constantes
const int led = 8;    //constante led refere-se ao pino digital 8.
const int botao = 2;  //constante botão refere-se ao pino digital 2.

//Declaração da variável que conterá os estados do botão (0 LOW, 1 HIGH).
int estadoBotao = 0;

//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  pinMode(led,OUTPUT);   //Definindo o pino digital 8 como de saída.
  pinMode(botao,INPUT);  //Definindo o pino digital 2 como pino de entrada. 
}

//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  //Lendo o estado do pino 2, constante botao, e atribuindo 
  //o resultado a variável estadoBotao.
  estadoBotao = digitalRead(botao);      

  if(estadoBotao==1){
  digitalWrite(led,HIGH);
  }else{
  digitalWrite(led,LOW);
  }

  //Verificando o estado do botão para definir se acenderá ou
  //apagará o led.  
  //  if (estadoBotao == 1) {
  //    digitalWrite(led,HIGH); //Botão pressionado, acende o led.
  //    
  //  } else if(estadoBotao==0){
  //  digitalWrite(led,LOW);
  //  }

}

