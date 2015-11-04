/*
 * GccApplication1.c
 *
 * Created: 2015-11-04 16:15:14
 *  Author: Administrator
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
  while(1)
  {
		for(int i=0; i<8; i++)
		{
			PORTA = 1 << i;
			_delay_ms(800);
		}
		_delay_ms(800);
		
		for(int i=7; i>=0; i--)
		{
			PORTA = 1 << i;
			_delay_ms(800);
		}
		_delay_ms(800);
  }
}
