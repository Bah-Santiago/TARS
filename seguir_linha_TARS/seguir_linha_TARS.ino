#include <robo_hardware2.h> 
#include <Servo.h>

#define DIVISOR_BRANCO_PRETO 97

float valorSensorDir;
float valorSensorEsq;

void setup(){
	robo.configurar(false);
}

void loop(){

	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir

	//Identifica se os dois sensores viram branco
	if(valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(48,48);	//Aciona os dois motores com a mesma velocidade
    delay(80);
	}
	//Identifica se o sensor da esquerda viu banco e o da direita viu preto
	else if (valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(50,-65);	//Aciona o motor esquerdo e mantem o motor direito desligado
    delay(150);
	}
	//Identifica se o sensor da direita viu banco e o da esquerda viu preto
	else if ( valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(-65,50);	//Aciona o motor direito e mantem o motor esquerdo desligado
    delay(150);
	}
	else{ //Identifica se os dois sensores viram preto
    robo.acionarMotores(65,65);
    delay(80);
	}
}

