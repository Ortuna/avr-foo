TARGET_CPU=atmega328p

CC=avr-gcc
CC_FLAGS=-mmcu=$(TARGET_CPU) -Os

OBJ_COPY=avr-objcopy
OBJ_FLAGS=-R .eeprom -O ihex 

FLASHER=avrdude
DEVICE=/dev/tty.usbserial-14310

.PHONY: clean

clean:
	rm -r image.out
	rm -r image.hex

main:
	$(CC) $(CC_FLAGS) $@.c -o image.out

image: main
	$(OBJ_COPY) $(OBJ_FLAGS) image.out $@.hex

flash: image
	$(FLASHER) -p $(TARGET_CPU) -cstk500v1 -P $(DEVICE) -U flash:w:image.hex -b57600

