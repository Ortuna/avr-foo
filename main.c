#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t timer_overflow = 0;

ISR(TIMER0_OVF_vect) {
  if(timer_overflow > 6) {
    timer_overflow = 0;

    PORTB ^= (0x01 << PB5);
    PORTD ^= (0x01 << PD2);
  }

  timer_overflow++;
}

int main()
{
  DDRB |= (0x01 << PB5);
  DDRD |= (0x01 << PD2);

  TCCR0A = 0x00;
  TCCR0B = (0x01 << CS01) | (0x01 << CS00);

  TIMSK0 = (0x01 << TOIE0);

  sei();
  while(1) { }
}
