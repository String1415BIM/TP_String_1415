all: test.out



test_main.o: test_main.cpp
	g++ -g -c test_main.cpp -o test_main.o

String.o: String.h String.cpp
	g++ -g -c String.cpp -o String.o

test.out: test_main.o String.o
	g++ -g test_main.o String.o -o test.out

clean:
	rm *.o

mrproper: clean
	rm test.out
