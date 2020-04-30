#define F_CPU 16000000
#include <avr/io.h>
 
uint8_t timer_overflow = 0;

int main()
{
  DDRB |= (1 << PB5);    // Make pin 13 be an output.  

  //TIMSK0 = (0x01 << TOIE0);
  TCNT0  = 0x00;
  OCR0A  = 0xFF;

  TCCR0A = 0x00;
  TCCR0B |= (0x01 << CS02) | (0x01 << CS00);

  while(1)
  {
    if((TIFR0 & 0x01) == 1) {
      TIFR0 |= (0x1 << TOV0);

      timer_overflow++;
      if(timer_overflow == 6) {
        timer_overflow = 0;

        PORTB ^= (0x01 << PB5);
      }

    }
  }
}
