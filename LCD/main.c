#include "def_principais.h"//arquivo com as principais definições
#include "LCD.h" //conjunto de funções para o LCD

//definiçao para armazenar mensagem na memória flash

PROGMEM const char mensagem[] = " DADOS DE 4BITS!\0";

int main()
{
	DDRD = 0xFF; // PORTD como saída (pinos de IO do LCD)
  
	DDRB = 0xFF; // PORTB como saída (pinos de IO do LCD)
  
	inic_LCD_4bits(); // inicializa o LCD
  
	escreve_LCD(" INTERFACE DE"); // string armazenada na RAM
  
	cmd_LCD(0xC0,0); // desloca cursor para a segunda linha
  
	escreve_LCD_Flash(mensagem); // string armazenada na flash
  
	while(1){} //laço infinito
}
