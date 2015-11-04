/*
 * GccApplication2.c
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
	int x = 150;
  while(1)
  {
  	for(int i=0; i<x; i++){
	  	PORTA = ~PORTA;
	  	_delay_ms(x-i);
	  	PORTA = ~PORTA;
	  	_delay_ms(i);
	  }
		
	  for(int i=x; i>=0; i--){
		  PORTA = ~PORTA;
		  _delay_ms(x-i);
		  PORTA = ~PORTA;
		  _delay_ms(i);
	  }
  }
}
