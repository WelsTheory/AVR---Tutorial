/*
 * Int_Ext.c
 *
 * Created: 28/10/2020 15:23:28
 * Author : Wels
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t i = 0;

int main(void)
{
	DDRC = 0xFF;// Salida Puerto C
	DDRD &= ~(1<<0); //INT0 PD0 ENTRADA
	EIMSK |= (1<<0); // INT0 HABILITADO; 
    EICRA = 0X02;// aNY CHANGE
	sei();// Habilitando Interrupciones 
    while (1) 
    {
		if (i == 1)
		{
			PORTC = 0XA0;
		}
		else{
			PORTC = 0x50;
		}
    }
}

ISR (INT0_vect){
	i++;
	if(i == 2){
		i = 0;
	}
}
