#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char contador = 0;

ISR(INT0_vect)
{
	contador++;
	_delay_ms(150);
}

int main(void)
{
	DDRD=0b1;
	DDRA=255;
	PORTD=4;
	
	GICR=(1<<INT0);
	
	MCUCR= (1<<ISC00)|(1<<ISC01);
	
	sei();
	
	char bcd[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};
	
	while(1)
	{
		PORTA=bcd[contador];	
	}
}