import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

pins = [7, 13, 19, 26]

for pin in pins:
	GPIO.setup(pin, GPIO.OUT)

def blink(speed, pin):
	GPIO.output(pin, False)
	time.sleep(speed/2.0)
	#GPIO.output(pin, True)
	time.sleep(speed/2.0)

for i in range(0, 10):
	for pin in pins:
		blink(0.5, pin)
