#all:
#	gcc -o gyro-acc-testmod -l rt gyro-acc.c -lm

testmod:
	gcc -l rt gyro-acc.c -lm

test:
	g++ -o main -std=c++11 -L./ -L../PIGPIO/ testFlight.cpp 
