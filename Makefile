CC = gcc
C = gcc

CFLAGS = -lrt -lm

all: 
	$(CC) $(CFLAGS) freqTest.c -o freqTest.o 
	
clean:
	rm *.o 
