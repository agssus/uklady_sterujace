#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int digits[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,0x80, 0x90};
int temp_time_counter = 0;
int time = 0;

int column1 = ~0xF1;
int column2 = ~0xF2;
int column3 = ~0xF4;
int column4 = ~0xF8;

int column_chooser = 0;
	
ISR(TIMER0_COMP_vect){
	
	if(column_chooser == 0){
		PORTB = column1;
		PORTA = digits[time % 10];
	}
	else if (column_chooser == 1){
		PORTB = column2;
		PORTA = digits[(time/10) % 10];
	}
	else if(column_chooser == 2){
		PORTB = column3;
		PORTA = digits[(time/100) % 10];
	}
	else if (column_chooser == 3){
		PORTB = column4;
		PORTA = digits[(time/1000) % 10];
	}
	
	column_chooser = (column_chooser + 1) % 4;
	
	temp_time_counter++;
	if(temp_time_counter >= 1000){
		time++;
		temp_time_counter = 0;
	}
}

int main(void)
{
	TCCR0 = (1 << WGM01) | (0 << WGM00) | (1 << CS00) | (1 << CS01) | (0 << CS02);
	OCR0 = 250;
	TIMSK |= 1 << OCIE0;
	
	sei();
	
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = ~0xF8;
	
    while(1)
    {}
}
