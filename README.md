# Main

- compile with: `avr-gcc -mmcu=atmega328p main.c -Os`
- setup raw output for flash: `avr-objcopy -R .eeprom -O ihex a.out out.hex` 
- send: `avrdude -p atmega328p -cstk500v1 -P /dev/tty.usbserial-1410 -U flash:w:out.hex -b57600`

