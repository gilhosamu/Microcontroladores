#include "def_principais.h"
#include "LCD.h"
int main()
{
	unsigned char segundos[2]; //var para os segundos individuais
	unsigned char minutos[2]; //var para os minutos individuais
	unsigned char horas[2]; //var para os horas individuais
	unsigned char seg=0;
	unsigned char min=0;
	unsigned char hor=0;
	
	unsigned char dia[2];
	unsigned char mes[2];
	unsigned char ano[2];
	unsigned char d=4;
	unsigned char m=5;
	unsigned char a=22;	
	
	DDRD = 0xFF; //PORTD como saída
	DDRB = 0xFF; //PORTB como saída
	PORTB = 0XFF;
	DDRC = 0b11111110;
	PORTC = 1;
	
	inic_LCD_4bits(); //inicializa o LCD
	
	char display=0;
	
	while(1)
	{
		seg++;
		if (seg>59){
			min++;
			seg=0;
		}
		if (min>59){
			hor++;
			min=0;
		}
		if (hor>23){
			d++;
			hor=0;
		}
		if (d>30){
			m++;
			d=1;
		}
		if (m>12){
			a++;
			m=1;
		}
		
		if(!tst_bit(PINC,0))
		{
			 cpl_bit(display,0);
			
		}
		
		if(display==1)
		{
			
		
		
		
		ident_num(seg,segundos);
		cmd_LCD(0x8A,0); //desloca o cursor
		cmd_LCD(segundos[1],1);
		cmd_LCD(segundos[0],1);
		
		ident_num(min,minutos);
		cmd_LCD(0x87, 0);
		cmd_LCD(minutos[1],1);
		cmd_LCD(minutos[0],1);
		cmd_LCD(':',1);
		
		ident_num(hor,horas);
		cmd_LCD(0x84, 0);
		cmd_LCD(horas[1],1);
		cmd_LCD(horas[0],1);
		cmd_LCD(':',1);
		
		
		
		ident_num(d,dia);
		cmd_LCD(0xC4,0);
		cmd_LCD(dia[1],1);
		cmd_LCD(dia[0],1);
		cmd_LCD('/',1);
		
		ident_num(m,mes);
		cmd_LCD(mes[1],1);
		cmd_LCD(mes[0],1);
		cmd_LCD('/',1);	
		
		ident_num(a,ano);
		cmd_LCD(ano[1],1);
		cmd_LCD(ano[0],1);
		
		}
		
		else {
			cmd_LCD(1,0);
			cmd_LCD(0x85, 0);
			escreve_LCD("SAMUEL");
			cmd_LCD(0xC6, 0);
			escreve_LCD("YGOR");
			
		}
		
		_delay_ms(1000); //tempo para a troca de valor
	}
}
