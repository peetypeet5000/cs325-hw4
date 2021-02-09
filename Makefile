CC = g++ -std=c++11 -g -Wall
all: activity

activity: util.o activity.o mergesort.o
	$(CC) util.o activity.o mergesort.o -o activity

util.o: util.cpp util.h
	$(CC) -c util.cpp
activity.o: activity.cpp activity.h
	$(CC) -c activity.cpp
mergesort.o: mergesort.cpp mergesort.h
	$(CC) -c mergesort.cpp


clean:
	rm *.o activity

