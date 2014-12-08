all: test.out

test.out: test_main.cpp String.o
	g++ -o test.out test_main.cpp String.o -Wall

String.o: String.cpp String.h
	g++ -o String.o -c String.cpp -Wall