/*
 * Timer0_Temporizador.c
 *
 * Created: 7/11/2020 16:16:42
 * Author : Wels
 */ 
#define F_CPU	16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

#define LEDS_DDR	DDRC
#define LEDS		PORTC

// Temporizador 1ms -> 250 => 250ms
#define Tiempo		194

uint8_t cuenta = 0;
uint8_t valor = 0;

int main(void)
{
	LEDS_DDR = 0xFF;// PUERTO C SALIDA
	LEDS = 0x00; // PUERTO C APAGADO
	TCCR0A = 0x00;
	TCCR0B = 0x04;// Prescaler 256 y Temporizador
	TCNT0 = Tiempo; // 194 -> 1ms
	TIFR0 |= (1<<TOV0); // LIMPIANDO INTERRUPCION
	TIMSK0 |= (1<<0); // HABILITANDO INTERRUPCION
	sei(); 
    while (1) 
    {
    }
}

ISR (TIMER0_OVF_vect){
	TCNT0 = Tiempo;// VUELVE A CARGAR EL VALOR TIEMPO 1MS
	cuenta++; //cuenta aumenta de 1 en 1
	if (cuenta == 250)
	{
		cuenta = 0;
		valor++;
		if (valor > 15)
		{
			valor = 0;
		}
		LEDS = valor;
	}
}

