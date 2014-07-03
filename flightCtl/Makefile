#all:
#	gcc -o gyro-acc-testmod -l rt gyro-acc.c -lm
CFLAGS=-std=c++11 -L./ -L../PIGPIO
testmod:
	gcc -l rt gyro-acc.c -lm

test:
	g++ -c $(CFLAGS) *.cpp
	g++ -o main $(CFLAGS) *.o 
#	rm main
