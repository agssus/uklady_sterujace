#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

int count = 0;

ISR(INT0_vect){
   
    count++;

    PORTA = count;
    PORTA = PORTA << 1;
}


int main(void)
{
    DDRA = 0xFF;
    DDRD = 1<<PD2;       
   
    PORTD = 1<<PD2;

    GICR = 1<<INT0;                   
    MCUCR = 1<<ISC01 | 1<<ISC00;   

    sei();
    while(1)
    {
        PORTA |= 0x01;
        _delay_ms(400);
        PORTA &= 0xFE;
        _delay_ms(400);
    }
}
