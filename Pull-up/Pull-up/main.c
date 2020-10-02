/*
 * Pull-up.c
 *
 * Created: 30/09/2020 17:02:11
 * Author : Wels
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRK &= ~_BV(0); //-> _BV(0) -> 1>> BIT 0;// entradas K0
	PORTK |= _BV(0);// habilita resistencias pull up pk0
	DDRF = 0xFF;
	PORTF = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		//if (!(PINK & (1<<0)))
		if(bit_is_clear(PINK,PK0))
		{
			PORTF = 0x05;
		}
		else{
			PORTF = 0x0A;
		}
    }
}

