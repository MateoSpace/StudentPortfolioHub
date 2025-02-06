//#include <F_CPU>
#include <asf.h>

#define led_on 1
#define led_off 0

int main (void)
{
	DDRA = 0b00001111;
	//DDRB = 0b00100000;
	PORTA= 0b11110000;
	char extra;
	
	while (1)
	{
		extra = PINA&0b11110000;
		PORTA = (extra>>4)|0b11110000;
	}
}
