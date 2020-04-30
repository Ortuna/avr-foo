#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
 
void delay_ms(int n) {
 while(n--) {
  _delay_ms(1);
 }
}

int main()
{
  DDRB |= (1 << PB5);    // Make pin 13 be an output.  
  while(1)
  {
    PORTB |= (1 << PB5);
    delay_ms(4500);
    PORTB &= ~(1 << PB5);
    delay_ms(4500);
  }

  printf("%x", DDRB);
}
