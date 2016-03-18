clock:	clock.o forteenSegmentDisplay.o
	gcc clock.o forteenSegmentDisplay.o -o clock -lpigpio -lrt

clock.o: clock.c forteenSegmentDisplay.h
	gcc -c clock.c -o clock.o

forteenSegmentDisplay.o: forteenSegmentDisplay.c forteenSegmentDisplay.h	
	gcc -c -Wall -pthread forteenSegmentDisplay.c -o forteenSegmentDisplay.o
