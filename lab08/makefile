L08a.out : Lab08a.o Square.o
	g++ -o L08a.out Lab08a.o Square.o

Lab08a.o : Lab08a.cpp Square.h
	g++ -c Lab08a.cpp

Square.o : Square.cpp Square.h
	g++ -c Square.cpp

L08b.out : Lab08b.o Square.o
	g++ -o L08b.out Lab08b.o Square.o

Lab08b.o : Lab08b.cpp Square.h
	g++ -c Lab08b.cpp

clean :
	rm -f *.o L08[ab].out
