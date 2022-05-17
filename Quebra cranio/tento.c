#include "def_principais.h"
#include "LCD.h"
int main()
{
	DDRD = 0xFF; //PORTD como saída
	DDRB = 0xFF; //PORTB como saída
	inic_LCD_4bits(); //inicializa o LCD
	
	int i;
		
		for(i=0; i<=2;i++){
		cmd_LCD(0xC0+i,0);
		cmd_LCD(0xFF,1);		
		}

		
		_delay_ms(1000); //tempo para a troca de valor

}
