#all:
#	gcc -o gyro-acc-testmod -l rt gyro-acc.c -lm
CC=g++
#CFLAGS=-static -std=c++11 -L./ -L../PIGPIO -L../gyro-acc -lpigpio -lpthread -lrt
COMPILEFLAGS=-static -std=c++11 -lpigpio -lpthread -lrt
OTHERFLAGS=-static -std=c++11 -lpigpio -lpthread -lrt

testmod:
	gcc -l rt gyro-acc.c -lm

test:
	g++ -c *.cpp $(COMPILEFLAGS) 
	g++ -o main *.o $(OTHERFLAGS) 
#	rm main


