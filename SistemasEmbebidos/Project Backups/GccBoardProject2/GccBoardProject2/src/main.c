
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

# define b_dat PORTA
# define b_dir PORTC
# define retardo _delay_ms(40)

volatile int contadoru = 0;
volatile int contadord = 0;
volatile int contadorc = 0;
volatile int contadorm = 0;

// Función de servicio de interrupción para INT0 (PD2)
ISR(INT0_vect) {
	// Reiniciar todos los contadores a 0
	contadoru = 0;
	contadord = 0;
	contadorc = 0;
	contadorm = 0;
}

int main(void) {
	// Configurar los puertos
	DDRC = 255;
	DDRA = 255;
	DDRD = 0b00000100;  // PD2 como entrada, PD2 con pull-up
	
	char bcd[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};
	
	// Configurar PD2 como entrada con resistencia pull-up
	DDRD &= ~(1 << PD2);  // PD2 como entrada
	PORTD |= (1 << PD2);  // Activar resistencia pull-up interna en PD2
	
	// Configurar interrupción INT0 en flanco de bajada
	MCUCR |= (1 << ISC01);   // Flanco de bajada en INT0
	MCUCR &= ~(1 << ISC00);
	
	// Habilitar interrupción externa INT0
	GICR |= (1 << INT0);
	
	// Habilitar interrupciones globales
	sei();
	
	while (1) {
		for (int i = 0; i < 5; i++) {
			b_dat = bcd[contadoru];
			b_dir = 0b1110;
			retardo;
			
			b_dat = bcd[contadord];
			b_dir = 0b1101;
			retardo;
			
			b_dat = bcd[contadorc];
			b_dir = 0b1011;
			retardo;
			
			b_dat = bcd[contadorm];
			b_dir = 0b0111;
			retardo;
		}
		
		contadoru++;
		if (contadoru == 10) {
			contadoru = 0;
			contadord++;
		}
		if (contadord == 10) {
			contadord = 0;
			contadorc++;
		}
		if (contadorc == 10) {
			contadorc = 0;
			contadorm++;
		}
		if (contadorm == 10) {
			contadorm = 0;
			contadorc = 0;
			contadord = 0;
			contadoru = 0;
		}
	}
}

