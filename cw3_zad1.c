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
	int column1 = ~0xF1;
	int column2 = ~0xF2;
	int column3 = ~0xF4;
	int column4 = ~0xF8;
	
	int digits[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,0x80, 0x90};
	int temp_time_counter = 0;
	
	while(1)
	{
		PORTB = column1;
		PORTA = digits[time % 10];
		_delay_ms(1);
		
		PORTB = column2;
		PORTA = digits[(time/10) % 10];
		_delay_ms(1);
		
		PORTB = column3;
		PORTA = digits[(time/100) % 10];
		_delay_ms(1);
		
		PORTB = column4;
		PORTA = digits[(time/1000) % 10];
		_delay_ms(1);
		temp_time_counter += 4;
		
		if(temp_time_counter > 1000){
			time++;
			temp_time_counter = 0;
		}
	}
}
