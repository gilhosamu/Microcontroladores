#include <avr/io.h>
#include "def_principais.h"
#include "LCD.h"
#include <stdlib.h>
 
 
int main(void)
{
	unsigned char imagem_n[4] = {1, 2, 3, 4};
	unsigned char imagem[4] = {1, 2, 3, 4};
		unsigned char a = 0;
		unsigned char b = 0;
		unsigned char c =0;
		unsigned char tentativas = 0;
		
		
	
	unsigned char i1[8] = {
		0b00000000,
		0b00011001,
		0b00010011,
		0b00000111,
		0b00001110,
		0b00011100,
		0b00011001,
		0b00010011
	};
	
	unsigned char i3[8] = {
		0b00010011,
		0b00011001,
		0b00011100,
		0b00001110,
		0b00000111,
		0b00010011,
		0b00011001,
		0b00000000
	};
	
	unsigned char i4[8] = {
		0b00011001,
		0b00010011,
		0b00000111,
		0b00001110,
		0b00011100,
		0b00011001,
		0b00010011,
		0b00000000
	};
	
	
	unsigned char i2[8] = {
		0b00000000,
		0b00010011,
		0b00011001,
		0b00011100,
		0b00001110,
		0b00000111,
		0b00010011,
		0b00011001
	};
	
	
	DDRD = 0xFF;
	DDRB = 0b00000011;
	PORTB = 0xFF;
	
	inic_LCD_4bits();
	
	cmd_LCD(0x83,0);
	escreve_LCD("PREPARE-SE");
	_delay_ms(1000);
	cmd_LCD(0x01,0);
	
	cmd_LCD(0x83,0);
	escreve_LCD("CARREGANDO");
	
	int x;
	
	for(x=0; x<=15;x++){
		cmd_LCD(0xC0+x,0);
		cmd_LCD(0xFF,1);
		_delay_ms(250);
		}
		
	_delay_ms(200);
	cmd_LCD(0x01,0);
	_delay_ms(150);
	
	cmd_LCD(0x48,0);
	for(k=0;k<8;k++)
		cmd_LCD(i1[k], 1);
	cmd_LCD(0x00,1);
	
	unsigned char k;
	
	cmd_LCD(0x50,0);
	for(k=0;k<8;k++)
	cmd_LCD(i2[k], 1);
	cmd_LCD(0x00,1);
	
	cmd_LCD(0x58,0);
	for(k=0;k<8;k++)
	cmd_LCD(i3[k], 1);
	cmd_LCD(0x00,1);
	
	cmd_LCD(0x60,0);
	for(k=0;k<8;k++)
	cmd_LCD(i4[k], 1);
	cmd_LCD(0x00,1);
	
	
	cmd_LCD(0x80,0);
	cmd_LCD(imagem[0],1);
	cmd_LCD(imagem[1],1);
	cmd_LCD(0xC0,0);
	cmd_LCD(imagem[2],1);
	cmd_LCD(imagem[3],1);
	
	

	_delay_ms(5000);

		
	for (k = 0; k < 4; k++)
	{
		unsigned char j = k + rand() / (RAND_MAX / (4 - k) + 1);
		unsigned char t = imagem[j];
		imagem[j] = imagem[k];
		imagem[k] = t;
	}
	
	cmd_LCD(0x80,0);
	cmd_LCD(imagem[0],1);
	cmd_LCD(imagem[1],1);
	cmd_LCD(0xC0,0);
	cmd_LCD(imagem[2],1);
	cmd_LCD(imagem[3],1);
	
	while(1){
		
		if (!tst_bit(PINB, PB2))
		{
			
			if(c==0){
				a=imagem[0];
				b=0;
				c++;
			}
			else
			{
				imagem[b] = imagem[0];
				imagem[0]= a;
				
				b=0;
				a=0;
				c++;
			}
			while(!tst_bit(PINB, PB2));
		}
		if (!tst_bit(PINB, PB3))
		{
			
			if(c==0){
				a=desenho[1];
				b=1;
				c++;
			}
			else
			{
				desenho[b] = imagem[1];
				imagem[1]= a;
				
				b=0;
				a=0;
				c++;
			}
			while(!tst_bit(PINB, PB3));
		}
		if (!tst_bit(PINB, PB4))
		{
			
			if(c==0){
				a=imagem[2];
				b=2;
				c++;
			}
			else
			{
				
				imagem[b] = imagem[2];
				imagem[2]= a;
				b=0;
				a=0;
				c++;
			}
			while(!tst_bit(PINB, PB4));
			
		}
		if (!tst_bit(PINB, PB5))
		{

			if(c==0){
				a=imagem[3];
				b=3;
				c++;	
			}
			else
			{
				imagem[b] = imagem[0];
				imagem[3]= a;
				
				b=0;
				a=0;
				c++;
			}
			while(!tst_bit(PINB, PB5));
		}
		if (c==2){
			
			cmd_LCD(0x80,0);
			cmd_LCD(imagem[0],1);
			cmd_LCD(imagem[1],1);
			cmd_LCD(0xC0,0);
			cmd_LCD(imagem[2],1);
			cmd_LCD(imagem[3],1);
			
			_delay_ms(100);
			
			c=0;
			tentativas++;
		}
		
		
		int vitoria = 1;
		for (int i = 0; i < 4; i++) {
			if (imagem[i] != imagem_n[i]) {
				vitoria = 0;
				break;
			}
		}
		if (vitoria == 1) {
			cmd_LCD(1,0);
			cmd_LCD(0x80,0);
			escreve_LCD("Parabens");
			cmd_LCD(0xC0,0);
			escreve_LCD("Voce Venceu");
			while(1);
		}
		
		if (tentativas >= 3) {
			cmd_LCD(1,0);
			cmd_LCD(0x80,0);
			escreve_LCD("Voce Perdeu");
			cmd_LCD(0xC0,0);
			escreve_LCD("Tente novamente");
			while(1);
		}
		

		}
		
		
			
	}
