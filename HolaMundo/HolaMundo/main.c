/*
 * HolaMundo.c
 *
 * Created: 9/09/2020 18:43:59
 * Author : Wels
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0XFF; // PUERTO B SALIDA
    /* Replace with your application code */
    while (1) 
    {
		PORTB = 0xA0;
		_delay_ms(500);
		PORTB = 0x50;
		_delay_ms(500); 
    }
}

