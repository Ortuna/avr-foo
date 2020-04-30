#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
 
int direction = 1;
int dev = 5;

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
    PORTB |= (1 << PB5);   // Turn the LED on.
    delay_ms((int) (1500 / dev));
    PORTB &= ~(1 << PB5);  // Turn the LED off.
    delay_ms((int) (1500 / dev));

    if (dev >= 10 || dev <= 1)
      direction = direction == 1 ? 0 : 1;

    dev += direction == 1 ? 1 : -1;

  }
}
