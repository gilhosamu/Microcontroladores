/*
 * GccApplication1.c
 *
 * Created: 26/04/2022 15:45:03
 *  Author: Aluno
 */


#include <avr/pgmspace.h> // biblioteca para poder gravar dados na memória flash
#define DISPLAY PORTD // define um nome auxiliar para o display
#define F_CPU 16000000UL /*define a freq. do ucontrolador para uso das rotinas de atraso*/
#include <avr/io.h> //definições do componente especificado
#include <util/delay.h> //biblioteca para as rotinas de _delay_ms() e delay_us()
//Definições de macros - para o trabalho com os bits de uma variável
#define set_bit(Y,bit_x)(Y|=(1<<bit_x)) //ativa o bit x da variável Y (coloca em 1)
#define clr_bit(Y,bit_x)(Y&=~(1<<bit_x)) //limpa o bit x da variável Y (coloca em 0)
#define cpl_bit(Y,bit_x)(Y^=(1<<bit_x)) //troca o estado do bit x da variável Y
#define tst_bit(Y,bit_x)(Y&(1<<bit_x)) //testa o bit x da variável Y (retorna 0 ou 1)

// variável gravada na memória flash
const unsigned char Tabela[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02,
0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};
char linha[4] = {PB0, PB1, PB2, PB3};
char flag = 0; 
//char coluna[4] = {PC0, PC1, PC2, PC3};
int main()
{
    unsigned char valor = 0; // declara variável local
    DDRB = 0b00100000; // PORTB como input
    PORTB= 0b11011111; // habilita o pull-up do PB0
    DDRC = 0xFF; //PORTC como output
    PORTC = 0xFF;
    //DDRD = 0xFF; // PORTD como saída (display)
    //PORTD= 0x00; // desliga o display
    
    while(1)
    {

   	 PORTC = 0b11111110;
   	 for(int i = 0; i < 4; i++){
   		 if(!tst_bit(PINB,linha[i]))
   		 {
			 flag = 1;
   			 if(i == 0){
   				 valor = 1;
   			 }
   			 if(i == 1){
   				 valor = 2;
   			 }
   			 if(i == 2){
   				 valor = 3;
   			 }
   			 
   		 }
   	 }
   	 PORTC = 0b11111101;
   	 for(int i = 0; i < 4; i++){
   		 if(!tst_bit(PINB,linha[i]))
   		 {
			 flag = 1;
   			 if(i == 0){
   				 valor = 4;
   			 }
   			 if(i == 1){
   				 valor = 5;
   			 }
   			 if(i == 2){
   				 valor = 6;
   			 }
   			 
   		 }
   	 }
   	 PORTC = 0b11111011;
   	 for(int i = 0; i < 4; i++){
   		 if(!tst_bit(PINB,linha[i]))
   		 {
			 flag = 1;
   			 if(i == 0){
   				 valor = 7;
   			 }
   			 if(i == 1){
   				 valor = 8;
   			 }
   			 if(i == 2){
   				 valor = 9;
   			 }
   			 
   		 }
   	 }
   	 PORTC = 0b11110111;
   	 for(int i = 0; i < 4; i++){
   		 if(!tst_bit(PINB,linha[i]))
   		 {
			 flag = 1;
   			 if(i == 0){
   				 valor = 10;
   			 }
   			 if(i == 1){
   				 valor = 0;
   			 }
   			 if(i == 2){
   				 valor = 11;
   			 }
   			 
   		 }
   	 }
	
	 if(flag){
		 for(int i = 0; i < valor; i++)
		 {
			 set_bit(PORTB, PB5);
			 _delay_ms(200);
			 clr_bit(PORTB, PB5);
			 _delay_ms(200);
		 }
		 flag = 0;
	 }
   	 //DISPLAY = pgm_read_byte(&Tabela[valor]);
    }
}
