#include "def_principais.h"//arquivo com as principais definições
#include "LCD.h" //conjunto de funções para o LCD
//definiçao para armazenar mensagem na memória flash
PROGMEM const char mensagem[] = " DADOS DE 4BITS!\0";
//----------------------------------------------------------------
int main()
{
	DDRD = 0xFF; // PORTD como saída (pinos de IO do LCD)
	DDRB = 0xFF; // PORTB como saída (pinos de IO do LCD)
	
	inic_LCD_4bits(); // inicializa o LCD
	
	escreve_LCD(" INTERFACE DE"); // string armazenada na RAM
	cmd_LCD(0xC0,0); // desloca cursor para a segunda linha
	escreve_LCD_Flash(mensagem); // string armazenada na flash
	
	char i = 0xC0;
	char j = 0x80;
			
	while(1){
		_delay_ms(300);
		cmd_LCD(1,0);
		
		cmd_LCD(i,0);
		cmd_LCD('S',1);
		_delay_ms(100);
		cmd_LCD('A',1);
		_delay_ms(100);
		cmd_LCD('M',1);
		_delay_ms(100);
		cmd_LCD('U',1);
		_delay_ms(100);
		cmd_LCD('E',1);
		_delay_ms(100);
		cmd_LCD('L',1);
		_delay_ms(100);
		
		cmd_LCD(j,0);
		cmd_LCD('Y',1);
		_delay_ms(100);
		cmd_LCD('G',1);
		_delay_ms(100);
		cmd_LCD('O',1);
		_delay_ms(100);
		cmd_LCD('R',1);
		_delay_ms(100);
		
		i++;
		j++;
		
		if(i>0xD0)
			i=0xC0;
		if(j>0x90)
			j=0x80;
			
		} //laço infinito
}
