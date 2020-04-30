#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
 
uint8_t timer_overflow = 0;

ISR(TIMER0_OVF_vect) {
  timer_overflow++;
  if(timer_overflow == 6) {
    timer_overflow = 0;

    PORTB ^= (0x01 << PB5);
  }
}

int main()
{
  DDRB |= (1 << PB5);    // Make pin 13 be an output.  

  TIMSK0 = (0x01 << TOIE0);
  TCNT0  = 0x00;
  OCR0A  = 0xFF;

  TCCR0A |= (0x01 << WGM00) | (0x01 << WGM01);
  TCCR0B |= (0x01 << CS02) | (0x01 << CS00);

  sei();

  while(1) { }
}
