CC = g++ -std=c++11 -g -Wall
all: activity

activity: util.o activity.o
	$(CC) util.o activity.o -o activity

util.o: util.cpp util.h
	$(CC) -c util.cpp
activity.o: activity.cpp activity.h
	$(CC) -c activity.cpp


clean:
	rm *.o activity

