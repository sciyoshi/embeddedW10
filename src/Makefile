#Update these vars accordingly

C32DIR	= /home/ben/.wine/drive_c/Program\ Files/Microchip/MPLAB\ C32/bin
PROC	= 32MX695F512H

CC	= wine $(C32DIR)/pic32-gcc.exe -s -mprocessor=$(PROC) -I.
B2H	= wine $(C32DIR)/pic32-bin2hex.exe
HEX	= speakers.hex
SRCS	= speakers.c lcd.c
OBJS	= $(SRCS:.c=.o)

all: $(SRCS) $(HEX)

$(HEX): speakers.elf
	$(B2H) -a speakers.elf

speakers.elf: $(OBJS)
	$(CC) $(OBJS) -o speakers.elf

.c.o:
	$(CC) -c $< -o $@

clean:
	rm -f *.o *.elf *.hex
