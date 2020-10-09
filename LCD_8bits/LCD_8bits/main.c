/*
 * LCD_8bits.c
 *
 * Created: 8/10/2020 15:22:02
 * Author : Wels
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTC
#define E_pin  PA2
#define RW_pin PA1
#define RS_pin PA0

void LCD_Init(void);
void LCD_Caracter(unsigned char	data);
void LCD_Comando(unsigned char cmd);
void LCD_XY(int x, int y);
void LCD_Cadena(char *dat);

int main(void)
{
	LCD_Init();
	LCD_XY(1,5);
	LCD_Caracter('H');
	LCD_Caracter('O');
	LCD_Caracter('L');
	LCD_Caracter('A');
	_delay_ms(100);
	LCD_XY(0,0);
	LCD_Cadena(" Suscribete!! :)");
    while (1) 
    {
    }
}

void LCD_Init(void){
	DDRC = 0xFF;// PUERTO C SALIDA
	DDRA = 0x07;// PA0 PA1 PA2 SALIDA
	_delay_ms(15);
	LCD_Comando(0X30);
	_delay_ms(1);
	LCD_Comando(0X30);
	_delay_ms(1);
	LCD_Comando(0X30);
	_delay_ms(1);
	LCD_Comando(0X38); // LINEAS 5X8
	_delay_ms(1);
	LCD_Comando(0X0C); // DISPLAY ON
	_delay_ms(1);
	LCD_Comando(0X01); // LIMPIAR LCD
	_delay_ms(1);
	LCD_Comando(0X06); // DDRAM
	_delay_ms(1);
}

void LCD_Comando(unsigned char cmd){
	LCD_DATA = cmd;//cmd = 0x30 
	//RS = 0 COMANDO - RW = 0 ESCRITURA - E = 1
	PORTA = (((1<<E_pin) | ~(1<<RS_pin)) & ~(1<<RW_pin));
	/*
		(1<<E_pin) -> PA2 1  0B00000100 |
	   ~(1<<RW_pin) -> PA1 1 0B11111101 
							 0B11111101 &
	   ~(1<<RS_pin) -> PA0 1 0B11111110
							 0B11111100
	*/ 
	_delay_ms(1);
	PORTA &= ~(1<<E_pin);
	_delay_ms(50);
}

void LCD_Caracter(unsigned char	data){
	LCD_DATA = data; 
	//RS = 1 CARACTER - RW = 0 ESCRITURA - E = 1
	PORTA = (((1<<E_pin) | (1<<RS_pin)) & ~(1<<RW_pin));
	/*
		(1<<E_pin) ->  1  0B00000100 |
	    (1<<RS_pin) ->  1 0B00000001 
						  0B00000101
	   ~(1<<RW_pin) ->  1 0B11111101 &
						  0B00000101
	*/ 
	_delay_ms(1);
	PORTA &= ~(1<<E_pin);
	_delay_ms(50);
}

void LCD_XY(int x, int y){
	//LINEA 1 0X80
	//LINEA 2 0XC0
	if(	x > 0){
		LCD_Comando(0xC0+y);
	}
	else{
		LCD_Comando(0x80+y);
	}
}

void LCD_Cadena(char *dat){
	//*dat = "hola\0"
	// dat++
	while(*dat != '\0'){
		LCD_Caracter(*dat);
		dat++;
	}
	
}


