/*
 * GccApplication1.c
 *
 * Created: 2015-11-25 16:12:54
 *  Author: Administrator
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = ~0xF8;
	
	int time = 0;
	int d1 = ~0xF1;
	int d2 = ~0xF2;
	int d3 = ~0xF4;
	int d4 = ~0xF8;
	
	int digits[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,0x80, 0x90};
	int a = 0;
	
	
    while(1)
    {
		PORTB = d1;
		PORTA = digits[time%10];
		_delay_ms(1);
		
		PORTB = d2;
		PORTA = digits[(time/10)%10];
		_delay_ms(1);
		
		PORTB = d3;
		PORTA = digits[(time/100)%10];
		_delay_ms(1);
		
		PORTB = d4;
		PORTA = digits[(time/1000)%10];
		_delay_ms(1);
		a += 4;
		
		if(a>1000){
			time++;
			a=0;
		}
		
		
		/*
		for (int i=0; i<10; i++){
			PORTA= digits[i];
			_delay_ms(1000);
			time++;
		
		}
		*/
        //TODO:: Please write your application code 
    }
}
