lab1: main.o
	g++ -std=c++11 -g -Wall main.o -o lab1

main.o: main.cpp Node.h LinkedList.h Node.cpp LinkedList.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o lab1
