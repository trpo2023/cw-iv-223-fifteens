all: main

main: main.o
	g++ -Wall -std=c++11 main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp -o main.o

clean:
	rm -f main main.o
