/*
 * CFile1.c
 *
 * Created: 2015-12-09 16:22:44
 *  Author: Administrator
 */ 
#include "HD44780.h"
#include <util/delay.h>

#define F_CPU 16000000UL
#define E 0x10
#define RS 0x20

void WriteNibble(unsigned char nibbleToWrite)
{
	PORTA |= (1<<E);
	PORTA = (PORTA & 0xF0) | (nibbleToWrite & 0x0F);
	PORTA &= ~(1 << E);
}


void WriteByte(unsigned char dataToWrite)
{
	WriteNibble(dataToWrite >> 4);
	WriteNibble(dataToWrite);
}


void LCD_Command(unsigned char command)
{
	PORTA = (0 << RS);
	WriteByte(command);
};

void LCD_Text(char *)
{
};
void LCD_GoToXY(unsigned char, unsigned char)
{
};

void LCD_Clear(void)
{
};

void LCD_Home(void)
{
};

void LCD_Initalize(void)
{
	_delay_ms(50);
	for(int i=0; i<3; i++){
		WriteNibble(0x03);
		_delay_ms(5);
	}
	WriteNibble(0x02);
	_delay_ms(1);

	LCD_Command(0x2C);
	_delay_ms(1);
	
	LCD_Command(0x08);
	_delay_ms(1);
	
	LCD_Command(0x01);
	_delay_ms(1);
	
	LCD_Command(0x2C);
	_delay_ms(1);
	
};
