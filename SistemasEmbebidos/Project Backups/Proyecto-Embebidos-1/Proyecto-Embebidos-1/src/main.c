#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define F_CPU 8000000UL
#include <util/delay.h>

#define MAX_LEVEL 99
#define RESPONSE_TIMEOUT 2000  // Tiempo máximo para respuesta (en ms)

char bcd[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};  // Tabla para display de 7 segmentos

volatile uint8_t simon_sequence[100];
volatile uint8_t button_state = 0;
volatile uint8_t level = 1;
volatile uint8_t player_index = 0;
volatile uint8_t bool_showing_sequence = 1;
volatile uint8_t game_over = 0;

void init_hardware(void);
void show_level(uint8_t level);
void generate_simon_sequence(void);
void show_simon_sequence(void);
void check_player_input(uint8_t button);
void reset_game(void);
void start_response_timer(void);
void stop_response_timer(void);

int main(void) {
	init_hardware();
	generate_simon_sequence();
	show_simon_sequence();
	
	while (1) {
		show_level(level);
		if (bool_showing_sequence) {
			PORTA &= ~((1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7));
			show_simon_sequence();  // Mostrar la secuencia nuevamente
		}
		
		if (~PIND & (1 << PD0)) {
			PORTA |= (1 << PA4);
			} else {
			PORTA &= ~(1 << PA4);
		}
		
		if (~PIND & (1 << PD2)) {
			PORTA |= (1 << PA5);
			} else {
			PORTA &= ~(1 << PA5);
		}
		
		if (~PIND & (1 << PD4)) {
			PORTA |= (1 << PA6);
			} else {
			PORTA &= ~(1 << PA6);
		}
		
		if (~PIND & (1 << PD6)) {
			PORTA |= (1 << PA7);
			} else {
			PORTA &= ~(1 << PA7);
		}

		if (game_over) {
			for (uint8_t i = 0; i < 5; i++) {
				PORTA |= (1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7);
				_delay_ms(300);
				PORTA &= ~((1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7));
				_delay_ms(300);
			}
			reset_game();
		}
	}
}

// Interrupción INT1 para leer los botones y comprobar la secuencia
ISR(INT1_vect) {
	if (!bool_showing_sequence) {
		stop_response_timer();
		show_level(level);
		TCNT1 = 0;
		_delay_ms(50);
		button_state = (~PIND & ((1 << PD0) | (1 << PD2) | (1 << PD4) | (1 << PD6)));

		if (button_state & (1 << PD0)) check_player_input(0);
		else if (button_state & (1 << PD2)) check_player_input(1);
		else if (button_state & (1 << PD4)) check_player_input(2);
		else if (button_state & (1 << PD6)) check_player_input(3);
		start_response_timer();
	}
}

// Interrupción del temporizador cuando se supera el tiempo de respuesta
ISR(TIMER1_COMPA_vect) {
	game_over = 1;
}

void init_hardware() {
	DDRD &= ~((1 << PD0) | (1 << PD2) | (1 << PD4) | (1 << PD6));
	PORTD |= (1 << PD0) | (1 << PD2) | (1 << PD4) | (1 << PD6);
	
    // Configuración de pines para display de 7 segmentos y dígitos
    DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3);
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4);

	// Configuración de pines para LEDs
    DDRA |= (1 << PA4) | (1 << PA5) | (1 << PA6) | (1 << PA7);

	GICR |= (1 << INT1);
	MCUCR |= (1 << ISC11);
	
	TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
	OCR1A = (F_CPU / 1024) * (RESPONSE_TIMEOUT / 1000);
	TIMSK |= (1 << OCIE1A);
	
	sei();
}

void show_level(uint8_t level) {
	uint8_t tens = level / 10;
	uint8_t units = level % 10;

	// Configurar dígito 1 (decenas)
	PORTA &= ~(1 << PA0);  // Activar el primer dígito (D_1)
	PORTA |= (1 << PA1);   // Desactivar el segundo dígito (D_2)

	// Segmento A en PA3
	if (bcd[tens] & (1 << 0)) {  // Verifica si el bit A está encendido en bcd
		PORTA |= (1 << PA3);
		} else {
		PORTA &= ~(1 << PA3);
	}

	// Segmento B en PA2
	if (bcd[tens] & (1 << 1)) {  // Verifica si el bit B está encendido en bcd
		PORTA |= (1 << PA2);
		} else {
		PORTA &= ~(1 << PA2);
	}

	// Segmento C en PB0
	if (bcd[tens] & (1 << 2)) {  // Verifica si el bit C está encendido en bcd
		PORTB |= (1 << PB0);
		} else {
		PORTB &= ~(1 << PB0);
	}

	// Segmento D en PB1
	if (bcd[tens] & (1 << 3)) {  // Verifica si el bit D está encendido en bcd
		PORTB |= (1 << PB1);
		} else {
		PORTB &= ~(1 << PB1);
	}

	// Segmento E en PB2
	if (bcd[tens] & (1 << 4)) {  // Verifica si el bit E está encendido en bcd
		PORTB |= (1 << PB2);
		} else {
		PORTB &= ~(1 << PB2);
	}

	// Segmento F en PB3
	if (bcd[tens] & (1 << 5)) {  // Verifica si el bit F está encendido en bcd
		PORTB |= (1 << PB3);
		} else {
		PORTB &= ~(1 << PB3);
	}

	// Segmento G en PB4
	if (bcd[tens] & (1 << 6)) {  // Verifica si el bit G está encendido en bcd
		PORTB |= (1 << PB4);
		} else {
		PORTB &= ~(1 << PB4);
	}

	_delay_ms(10);

	// Configurar dígito 2 (unidades)
	PORTA |= (1 << PA0);   // Desactivar el primer dígito (D_1)
	PORTA &= ~(1 << PA1);  // Activar el segundo dígito (D_2)

	// Segmento A en PA3
	if (bcd[units] & (1 << 0)) {
		PORTA |= (1 << PA3);
		} else {
		PORTA &= ~(1 << PA3);
	}

	// Segmento B en PA2
	if (bcd[units] & (1 << 1)) {
		PORTA |= (1 << PA2);
		} else {
		PORTA &= ~(1 << PA2);
	}

	// Segmento C en PB0
	if (bcd[units] & (1 << 2)) {
		PORTB |= (1 << PB0);
		} else {
		PORTB &= ~(1 << PB0);
	}

	// Segmento D en PB1
	if (bcd[units] & (1 << 3)) {
		PORTB |= (1 << PB1);
		} else {
		PORTB &= ~(1 << PB1);
	}

	// Segmento E en PB2
	if (bcd[units] & (1 << 4)) {
		PORTB |= (1 << PB2);
		} else {
		PORTB &= ~(1 << PB2);
	}

	// Segmento F en PB3
	if (bcd[units] & (1 << 5)) {
		PORTB |= (1 << PB3);
		} else {
		PORTB &= ~(1 << PB3);
	}

	// Segmento G en PB4
	if (bcd[units] & (1 << 6)) {
		PORTB |= (1 << PB4);
		} else {
		PORTB &= ~(1 << PB4);
	}

	_delay_ms(10);
}

void generate_simon_sequence(void) {
	for (uint8_t i = 0; i < MAX_LEVEL; i++) {
		simon_sequence[i] = rand() % 4;
	}
}

void show_simon_sequence(void) {
	stop_response_timer();  // Detener temporizador al mostrar la secuencia
	_delay_ms(180);
	for (uint8_t i = 0; i < level; i++) {
		uint8_t led = simon_sequence[i];
		switch(led){
			case 0: 
				PORTA = (1 << PA4);
				_delay_ms(300);
				PORTA &= ~(1 << PA4);
				_delay_ms(300);
			break;
			case 1:
				PORTA = (1 << PA5);
				_delay_ms(300);
				PORTA &= ~(1 << PA5);
				_delay_ms(300);
			break;
			case 2:
				PORTA = (1 << PA6);
				_delay_ms(300);
				PORTA &= ~(1 << PA6);
				_delay_ms(300);
			break;
			case 3:
				PORTA = (1 << PA7);
				_delay_ms(300);
				PORTA &= ~(1 << PA7);
				_delay_ms(300);
			break;
		}

	}
	
	bool_showing_sequence = 0;
	start_response_timer();  // Iniciar temporizador después de mostrar la secuencia
}

void check_player_input(uint8_t button) {
	if (button == simon_sequence[player_index]) {
		player_index++;
		
		if (player_index == level) {  // Completó la secuencia
			level++;
			if (level > MAX_LEVEL) level = MAX_LEVEL;

			show_level(level);
			player_index = 0;  // Reiniciar para la siguiente ronda
			bool_showing_sequence = 1;
		}
	}
	else
	{
		game_over = 1;  // Error en la secuencia
	}
}

void reset_game(void) {
	level = 1;
	player_index = 0;
	bool_showing_sequence = 1;
	button_state = 0;
	game_over = 0;
	generate_simon_sequence();
	show_level(level);
}

void start_response_timer(void) {
	TCNT1 = 0;  // Reiniciar contador del Timer1
	TIMSK |= (1 << OCIE1A);  // Habilitar la interruPAión del temporizador
}

void stop_response_timer(void) {
	TIMSK &= ~(1 << OCIE1A);  // Deshabilitar la interruPAión del temporizador
}
