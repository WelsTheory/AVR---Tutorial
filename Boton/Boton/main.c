/*
 * Boton.c
 *
 * Created: 11/09/2020 17:13:43
 * Author : Wels
 */ 
#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	DDRB = 0xF0;// 1 -> salida y 0-> entrada
	DDRC &= 0b11111110;// PC0 -> Entrada
    /* Replace with your application code */
    while (1) 
    {
		if (PINC & (1<<0) )
			PORTB = (1<<7) | (1<<5);
		else
			//PORTB = (~(1<<7)) & (~(1<<5));
			PORTB &= 0x00;
    }
}

//PORTB -> ESCRIBIR
//PINC -> LEER 

/*
(1<<0) -> 1 logico al pin 0
00000000 -> (1<<0) 00000001
(1<<5) > 1 logico al pin 5
~(1<<7) -> 0 logico al pin 7
00000000 -> ~(1<<0) 11111110
*/