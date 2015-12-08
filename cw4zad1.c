#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int digits[10] = {0x81, 0xD7, 0x98, 0x94, 0xC6, 0xA4, 0xA0, 0xD5,0x80, 0x84};
int temp_time_counter = 0;
int button = 0;

int column1 = ~0xF1;
int column2 = ~0xF2;
int column3 = ~0xF4;
int column4 = ~0xF8;

int column_chooser = 0;

ISR(TIMER0_COMP_vect){
	
	if(column_chooser == 0){
		PORTB = column1;
		PORTA = digits[button % 10];
	}
	else if (column_chooser == 1){
		PORTB = column2;
		PORTA = digits[(button/10) % 10];
	}
	else if(column_chooser == 2){
		PORTB = column3;
		PORTA = digits[(button/100) % 10];
	}
	else if (column_chooser == 3){
		PORTB = column4;
		PORTA = digits[(button/1000) % 10];
	}
	
	column_chooser = (column_chooser + 1) % 4;

	delay();

}

void delay()
{
	for(int x = 100; x > 0; x--){}
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
	
	DDRD = 0xF0;
	PORTD = 0x0F;

	int wiersz = 0;
	int kolumna = 0;
	
	int tab[4][4] =
	{
		{16,15,14,13},
		{12,11,10,9},
		{8,7,6,5},
		{4,3,2,1},
	};
	
	while(1)
	{
		DDRD = 0xF0;
		PORTD = 0x0F;
		if (((~PIND) & (1 << 0)))
		{
			kolumna = 0;
		}
		if ((~PIND) & (1 << 1))
		{
			kolumna = 1;
		}
		if ((~PIND) & (1 << 2))
		{
			kolumna = 2;
		}
		if ((~PIND) & (1 << 3))
		{
			kolumna = 3;
		}
		
		DDRD = 0x0F;
		PORTD = 0xF0;
		delay();	
		if (((~PIND) & (1 << 4)))
		{
			wiersz = 0;
		}
		if ((~PIND) & (1 << 5))
		{
			wiersz = 1;
		}
		if ((~PIND) & (1 << 6))
		{
			wiersz = 2;
		}
		if ((~PIND) & (1 << 7))
		{
			wiersz = 3;
		}
		delay();	
		button = tab[wiersz][kolumna];
		delay();	
	}
}
