// Zadanie robione na plytce EVBavr05, stan 'zapalajacy' diode odpowiada bitowi 0 zamiast 
// 1 jak w przypadku plytek na cwiczeniach, stad negacja w liniach 20 i 25



#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

int main(void)
{
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<COM00)  //Fast PWM
	| (1<<CS00); // clock, bez prescalling
	DDRD = 0 << PD2 | 0 << PD3; // input dla klawiatury
	DDRB|=(1<<PB3); // output OCR na odpowiednia diode
	sei();
	
    while(1)
    {
		if (!(PIND & (1 << PD2))) // czy przycisk wcisniety?
		{
			OCR0+=1; //jasniej
			_delay_ms(20); // zeby bylo plynnie
		}
		if (!(PIND & (1 << PD3))) // czy przycisk wcisniety?
		{
			OCR0-=1; //ciemniej
			_delay_ms(20);
		}
	}

}
