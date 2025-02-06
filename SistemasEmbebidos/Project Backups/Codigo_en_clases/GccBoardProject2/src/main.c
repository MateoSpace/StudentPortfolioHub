
/*
#include <asf.h>
#include <util/delay.h>

#define led_on 1
#define led_off 0

int main (void)
{
	DDRA = 1;
	DDRB = 0;
	PORTA= 1;
		
	while (1)
	{
		if ((PINB&1)==1)
		{
			PORTA=led_off;
		}
		else
		{
			PORTA=led_on;
		}
	}
}
*/
/*
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

// Definir los patrones para el display de 7 segmentos (común cátodo)
// a, b, c, d, e, f, g


uint8_t segment_display_cathode[16] = {
	0b00111111,  // 0
	0b00000110,  // 1
	0b01011011,  // 2
	0b01001111,  // 3
	0b01100110,  // 4
	0b01101101,  // 5
	0b01111101,  // 6
	0b00000111,  // 7
	0b01111111,  // 8
	0b01101111,  // 9
	0b01110111,  // A
	0b01111100,  // B
	0b00111001,  // C
	0b01011110,  // D
	0b01111001,  // E
	0b01110001   // F
};

/*
uint8_t segment_display_anode[16] = {
	0b11000000,  // 0
	0b11111001,  // 1
	0b10100100,  // 2
	0b10110000,  // 3
	0b10011001,  // 4
	0b10010010,  // 5
	0b10000010,  // 6
	0b11111000,  // 7
	0b10000000,  // 8
	0b10010000,  // 9
	0b10001000,  // A
	0b10000011,  // B
	0b11000110,  // C
	0b10100001,  // D
	0b10000110,  // E
	0b10001110   // F
};*


void setup() {
	DDRC = 0xFF;  // puerto C como salida para los segmentos del display
	DDRB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2) & ~(1 << PB3);  // PB0, PB1, PB2, PB3 como entrada
	PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);    // Activar resistencias pull-up en los pines de entrada
}

uint8_t read_input() {
	// Leer los primeros cuatro bits del puerto B (PB0 a PB3)
	uint8_t input = PINB & 0x0F;  // Máscara para los primeros 4 bits (0 a 15)
	return input;
}

void display_number(uint8_t number) {
	// Mostrar el número en el display de 7 segmentos (usar el valor binario en segment_display_cathode)
	PORTC = segment_display_cathode[number];  // Enviar el patrón adecuado al puerto C
}

int main() {
	setup();  // Configuración inicial

	while (1) {
		uint8_t input = read_input();  // Leer el valor de los cuatro bits
		display_number(input);         // Mostrar el número correspondiente en el display
		_delay_ms(100);                // Pequeño retardo para evitar parpadeos
	}

	return 0;
}*/

/*
#include <avr/io.h>

int main(void) {
	// Configuramos el puerto A: PA0 a PA3 como salida y PA4 a PA7 como entrada
	DDRA = 0x0F;  // PA0-PA3 como salidas (0b00001111) y PA4-PA7 como entradas (0b11110000)

	while (1) {
		// Leemos el valor de los pines de entrada PA4 a PA7
		uint8_t input = PINA & 0xF0; // Máscara para PA4-PA7 (0b11110000)

		// Relacionamos las entradas con las salidas según el mapeo desordenado:
		// PA5 controla PA0
		// PA6 controla PA1
		// PA7 controla PA2
		// PA4 controla PA3

		// Limpiamos PA0 a PA3 antes de asignar los nuevos valores
		PORTA &= ~0x0F;  // Limpiamos PA0-PA3 (0b11110000)

		// Asignamos las salidas en PA0-PA3 según las entradas
		if (input & (1 << PA5)) PORTA |= (1 << PA0); // Si PA5 está en alto, poner PA0 en alto
		if (input & (1 << PA6)) PORTA |= (1 << PA1); // Si PA6 está en alto, poner PA1 en alto
		if (input & (1 << PA7)) PORTA |= (1 << PA2); // Si PA7 está en alto, poner PA2 en alto
		if (input & (1 << PA4)) PORTA |= (1 << PA3); // Si PA4 está en alto, poner PA3 en alto
	}

	return 0;
}
*/

#include <avr/io.h>

int main(void) {
	// Configurar PA0, PA2, PA4, PA6 como salidas y PA1, PA3, PA5, PA7 como entradas
	DDRA = (1 << PA0) | (1 << PA2) | (1 << PA4) | (1 << PA6);  // PA0, PA2, PA4, PA6 salidas
	PORTA |= ~DDRA;  // Habilitar pull-ups en los pines de entrada (PA1, PA3, PA5, PA7)

	while (1) {
		uint8_t input = PINA;  // Leer todas las entradas
		
		// Controlar las salidas según las entradas
		if (input & (1 << PA5)) PORTA &= ~(1 << PA0);  // Si PA5 está en alto, limpiar PA0
		else PORTA |= (1 << PA0);                      // Si PA5 está en bajo, poner PA0 en alto

		if (input & (1 << PA6)) PORTA &= ~(1 << PA1);  // Si PA6 está en alto, limpiar PA1
		else PORTA |= (1 << PA1);                      // Si PA6 está en bajo, poner PA1 en alto

		if (input & (1 << PA7)) PORTA &= ~(1 << PA2);  // Si PA7 está en alto, limpiar PA2
		else PORTA |= (1 << PA2);                      // Si PA7 está en bajo, poner PA2 en alto

		if (input & (1 << PA4)) PORTA &= ~(1 << PA3);  // Si PA4 está en alto, limpiar PA3
		else PORTA |= (1 << PA3);                      // Si PA4 está en bajo, poner PA3 en alto
	}

	return 0;
}
