#include "config.c"
#include <stdio.h>


/*
Utilize o Timer2 como base de tempo para o conversor digital/analógico interno (DAC0) do microcontrolador;­ 
Configure o Timer2 para que ocorram 10000 overflows por segundo;­
Utilize a ISR do Timer2 para atualizar os valores a serem convertidos pelo DAC.
*/
void delay_ms(unsigned int t)
{
TMOD |= 0x01;
TMOD &= ~0x02;
for(;t>0;t--)
	{
	TR0=0;
	TF0=0;
	TL0=0x58;	//1ms para 25000000
	TH0=0x9e;
	TR0=1;
	while(TF0==0);
	}
}


void putchar (char c) {
    SBUF0=c;
    while(TI0==0);
    TI0=0;
}


void main (void){
    unsigned char cont;
    Init_Device();
    SFRPAGE = LEGACY_PAGE;

    while(1){
        printf_fast_f("cont=%d\r",cont);
        delay_ms(1000);
        cont++;
        }
}






