/*
 * GccApplication1.c
 *
 * Created: 2015-11-25 16:12:54
 *  Author: Administrator
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>

int digits[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,0x80, 0x90};
	int a = 0;
	int time = 0;
	
	int d1 = ~0xF1;
	int d2 = ~0xF2;
	int d3 = ~0xF4;
	int d4 = ~0xF8;
	
	int b = 0;
	
ISR(TIMER0_COMP_vect){
	
	if(b == 0){
		PORTB = d1;
		PORTA = digits[time%10];
	}
	else if (b == 1){
		PORTB = d2;
		PORTA = digits[(time/10)%10];
	}
	else if(b == 2){
		PORTB = d3;
		PORTA = digits[(time/100)%10];
	}
	else if (b == 3){
		PORTB = d4;
		PORTA = digits[(time/1000)%10];
	}
	
	b = (b + 1) % 4;
	
	a++;
	if(a >= 1000){
		time++;
		a = 0;
	}
}

int main(void)
{
	
	TCCR0 = (1 << WGM01) | (0 << WGM00) | 1 << CS00 | 1 << CS01 | 0 << CS02;
	OCR0 = 250;
	TIMSK |= 1 << OCIE0;
	sei();
	
	
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = ~0xF8;
	
    while(1)
    {
	
    }
}


