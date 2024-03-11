
#include <SdFat.h>
SdFile meuArquivo;


int potenciometro = A0;
int led = 2;
float valor_lido = 0;

void setup(){

  pinMode(potenciometro, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  // Abre o arquivo LER_POT.TXT
  if (!meuArquivo.open("ler_pot.txt", O_RDWR | O_CREAT | O_AT_END))
  {
    sdCard.errorHalt("Erro na abertura do arquivo LER_POT.TXT!");
  }
  
  }
void loop(){
 /*
 Comando map(valor, deMenor, deMaior, paraMenor, paraMaior):Remapeia um número 
 de um intervalo para outro. Isto é, um valor de deMenor seria mapeado para 
 paraMenor, um valor de deMaior para  paraMaior, valores dentro de uma faixa 
 para volores dentro da outra faixa, etc.
*/ 
	valor_lido = map(analogRead(potenciometro),0,1023,0,255);
  	//Pega o valor lido e remapeia para o sinal está entre 0 e 5 V.
/*
Comando analogWrite(porta,valor): Aciona uma onda PWM em um pino. Pode ser usada 
para variar o brilho de um LED ou acionar um motor a diversas velocidades.
*/ 	
  	analogWrite(led,valor_lido);//Faz o LED brilhar na intensidade lida
/*
Comando Serial.println: Escreve e pula a linha no monitor serial do arduino
*/ 	
	Serial.println(valor_lido);//Escreve no monitor serial
/*Comando delay(tempo): pausa o programa por uma quantidade especifica de tempo
em milissegundos( 1000 = 1 s)
*/
 	delay(10);//Espera 10 millisegundos
  // Grava dados do potenciometro em LER_POT.TXT
  meuArquivo.print("Leitura Potenciometro: ");
  meuArquivo.println(valor);
}

