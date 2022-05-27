#include <avr/io.h>
#include "def_principais.h"
#include "LCD.h"
#include <stdlib.h>
 
 
int main(void)
{
	unsigned char desenho_n[4] = {1, 2, 3, 4};
	unsigned char desenho[4] = {1, 2, 3, 4};
		unsigned char x = 0;
		unsigned char y = 0;
		unsigned char z =0;
		unsigned char jogadas = 0;
		
		
	
	unsigned char c1[8] = {
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000011,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00010000
	};
	
	unsigned char c3[8] = {
		0b00010000,
		0b00010000,
		0b00001000,
		0b00000100,
		0b00000011,
		0b00000000,
		0b00000000,
		0b00000000
	};
	
	unsigned char c4[8] = {
		0b00000001,
		0b00000001,
		0b00000010,
		0b00000100,
		0b00011000,
		0b00000000,
		0b00000000,
		0b00000000
	};
	
	
	unsigned char c2[8] = {
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011000,
		0b00000100,
		0b00000010,
		0b00000001,
		0b00000001
	};
	
	
    unsigned char k;
	
	DDRD = 0xFF;
	DDRB = 0b00000011;
	PORTB = 0xFF;
	
	inic_LCD_4bits();
	
	cmd_LCD(0x48,0);
	for(k=0;k<8;k++)
		cmd_LCD(c1[k], 1);
	cmd_LCD(0x00,1);
	
	cmd_LCD(0x50,0);
	for(k=0;k<8;k++)
	cmd_LCD(c2[k], 1);
	cmd_LCD(0x00,1);
	
	cmd_LCD(0x58,0);
	for(k=0;k<8;k++)
	cmd_LCD(c3[k], 1);
	cmd_LCD(0x00,1);
	
	cmd_LCD(0x60,0);
	for(k=0;k<8;k++)
	cmd_LCD(c4[k], 1);
	cmd_LCD(0x00,1);
	
	
	cmd_LCD(0x80,0);
	cmd_LCD(desenho[0],1);
	cmd_LCD(desenho[1],1);
	cmd_LCD(0xC0,0);
	cmd_LCD(desenho[2],1);
	cmd_LCD(desenho[3],1);
	
	

	_delay_ms(5000); //tempo para a troca de valor

		
	for (k = 0; k < 4; k++)
	{
		unsigned char j = k + rand() / (RAND_MAX / (4 - k) + 1);
		unsigned char t = desenho[j];
		desenho[j] = desenho[k];
		desenho[k] = t;
	}
	
	cmd_LCD(0x80,0);
	cmd_LCD(desenho[0],1);
	cmd_LCD(desenho[1],1);
	cmd_LCD(0xC0,0);
	cmd_LCD(desenho[2],1);
	cmd_LCD(desenho[3],1);
	
	while(1){
		
		if (!tst_bit(PINB, PB2))
		{
			
			if(z==0){
				x=desenho[0];
				y=0;
				z++;
			}
			else
			{
				desenho[y] = desenho[0];
				desenho[0]= x;
				
				y=0;
				x=0;
				z++;
			}
			while(!tst_bit(PINB, PB2));
		}
		if (!tst_bit(PINB, PB3))
		{
			
			if(z==0){
				x=desenho[1];
				y=1;
				z++;
			}
			else
			{
				desenho[y] = desenho[1];
				desenho[1]= x;
				
				y=0;
				x=0;
				z++;
			}
			while(!tst_bit(PINB, PB3));
		}
		if (!tst_bit(PINB, PB4))
		{
			
			if(z==0){
				x=desenho[2];
				y=2;
				z++;
			}
			else
			{
				
				desenho[y] = desenho[2];
				desenho[2]= x;
				y=0;
				x=0;
				z++;
			}
			while(!tst_bit(PINB, PB4));
			
		}
		if (!tst_bit(PINB, PB5))
		{

			if(z==0){
				x=desenho[3];
				y=3;
				z++;	
			}
			else
			{
				desenho[y] = desenho[0];
				desenho[3]= x;
				
				y=0;
				x=0;
				z++;
			}
			while(!tst_bit(PINB, PB5));
		}
		if (z==2){
			
			cmd_LCD(0x80,0);
			cmd_LCD(desenho[0],1);
			cmd_LCD(desenho[1],1);
			cmd_LCD(0xC0,0);
			cmd_LCD(desenho[2],1);
			cmd_LCD(desenho[3],1);
			
			_delay_ms(100);
			
			z=0;
			jogadas++;
		}
		
		
		int ganhou = 1;
		for (int i = 0; i < 4; i++) {
			if (desenho[i] != desenho_n[i]) {
				ganhou = 0;
				break;
			}
		}
		if (ganhou == 1) {
			cmd_LCD(1,0);
			cmd_LCD(0x80,0);
			escreve_LCD("Boa ganho");
			while(1);
		}
		
		if (jogadas >= 3) {
			cmd_LCD(1,0);
			cmd_LCD(0x80,0);
			escreve_LCD("Perdeste");
			while(1);
		}
		

		}
		
		
			
	}
