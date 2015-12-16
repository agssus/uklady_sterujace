/*
 * CFile1.c
 *
 * Created: 2015-12-09 16:22:44
 *  Author: Administrator
 */ 

#include "HD44780.h"
#define F_CPU 16000000UL
#include <util/delay.h>


#define E 0x10
#define RS 0x20

void WriteNibble(unsigned char nibbleToWrite)
{
	PORTA |= E;
	PORTA = (PORTA & 0xF0) | (nibbleToWrite & 0x0F);
	PORTA &= ~E;
}


void WriteByte(unsigned char dataToWrite)
{
	WriteNibble(dataToWrite >> 4);
	WriteNibble(dataToWrite);
}


void LCD_Command(unsigned char command)
{
	PORTA &= ~RS;
	WriteByte(command);
};

void LCD_Text(char * text)
{

	PORTA |= RS;
	int i = 0;
	while (text[i] != '\0'){
		LCD_GoToXY(i,0);
		WriteByte(text[i++]);
	}

};

void LCD_GoToXY(unsigned char x, unsigned char y)
{
	_delay_ms(3);
	char adr = y*0x40 +x;
	PORTA = adr | 0x60;
	_delay_ms(3);
	
	
};
/*
void LCD_Clear(void)
{
};

void LCD_Home(void)
{
};
*/
void LCD_Initalize(void)
{
	_delay_ms(50);
	for(int i=0; i<3; i++){
		WriteNibble(0x03);
		_delay_ms(5);
	}
	WriteNibble(0x02);
	_delay_ms(2);

	LCD_Command(0x28);
	_delay_ms(2);
	
	LCD_Command(0x08);
	_delay_ms(2);
	
	LCD_Command(0x01);
	_delay_ms(2);
	
	LCD_Command(0x06);
	_delay_ms(2);
	
	LCD_Command(0x0f);
	_delay_ms(2);
	
};

int main(void){
	DDRA = 0xFF;
	LCD_Initalize();
	LCD_Text("text");
	while(1){
		
		
	}
	
}
