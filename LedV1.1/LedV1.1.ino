/*
 * Fita de LED RGB com Arduino
 *
 * Version 1.0.0
 *
 * Efeitos simples de cores e flash (strobo) com a fita de LED RGB no Arduino
 * Copyright 2013, Hugo Demiglio
 * 
 * Para maiores detalhes, veja http://www.youtube.com/watch?v=mSwRuOnOkTE
 *
 * @copyright     Copyright 2013, Hugo Demiglio, hugodemiglio@gmail.com
 * Twitter        http://twitter.com/hugodemiglio
 * @link          http://hgbrasil.com
 * 
 * Created on Hiperload.com - Simple share.
 */

#define RED 5 // pino PWM 5 para a cor vermelha
#define GREEN 9 // pino PWM 9 para a cor verde
#define BLUE 6 // pino PWM 6 para a cor azul

void setup(){
  // definindo os pinos como output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  // No setup, um teste das cores
  
  // Acende e apaga o vermelho
//  analogWrite(RED, 255);
//  delay(5000);
//  analogWrite(RED, 0);
//  
//  // Acende e apaga o verde
//  analogWrite(GREEN, 255);
//  delay(1000);
//  analogWrite(GREEN, 0);
//  
//  // Acende e apaga o azul
//  analogWrite(BLUE, 255);
//  delay(1000);
//  analogWrite(BLUE, 0);
//  
//  // Acendendo o azul, pois o loop do efeito de cores tem que começar com o azul aceso
//  delay(1000);
//  analogWrite(BLUE, 255);
}

void loop(){


  analogWrite(RED,255);
  delay(1000);
  analogWrite(GREEN,255);
  delay(1000);
  analogWrite(BLUE,255);
  delay(5000);
  analogWrite(RED,0);
  delay(1000);
  analogWrite(GREEN,0);
  delay(1000);
  analogWrite(BLUE,0);
}

void efeito_de_cores(){
  // Declara as variáveis dos loops
  int r, g, b;
  
  // Fade do azul (ja estava aceso) até o violeta, adicionando o vermelho
  for(r = 0; r <= 255; r++){
    analogWrite(RED, r);
    delay(10);
  }
  
  // Fade do violeta até o vermelho, removendo o azul
  for(b = 255; b >= 0; b--){
    analogWrite(BLUE, b);
    delay(10);
  }
  
  // Fade do vermelho até o amarelo, adicionando o verde
  for(g = 0; g <= 255; g++){
    analogWrite(GREEN, g);
    delay(10);
  }
  
  // Fade do amarelo até o verde, removendo o vermelho
  for(r = 255; r >= 0; r--){
    analogWrite(RED, r);
    delay(10);
  }
  
  // Fade do verde até o turquesa, adicionando o azul
  for(b = 0; b <= 255; b++){
    analogWrite(BLUE, b);
    delay(10);
  }
  
  // Fade do turquesa até o azul, removendo o verde
  for(g = 255; g >= 0; g--){
    analogWrite(GREEN, g);
    delay(10);
  }
  
  // Em seguida o loop continua, com o azul aceso
}

void strobo(){
  // Acende todas as cores juntas
  analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
  delay(50);
  
  // Apaga todas as cores juntas
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
  delay(50);
  
  // Como o delay é rápido, a fita da um efeito tipo strobo
}
void gradiente(){
  int r,g,b;
  r = 255;
  analogWrite(RED,r);
  delay(500);
  
}
