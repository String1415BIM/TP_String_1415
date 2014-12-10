all: test.out

test.out: test_main.o String.o
	g++ test_main.o String.o -o test.out

test_main.o: test_main.cpp
	g++ -c test_main.cpp -o test_main.o

String.o: String.h String.cpp
	g++ -c String.cpp -o String.o

clean:
	rm *.o

mrproper: clean
	rm test.out
