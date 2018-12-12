L11.out : FractionTest.o Fraction.o
	g++ -o L11.out FractionTest.o Fraction.o -g

FractionTest.o : DuarteL11app.cpp DuarteL11.hpp Fraction.h
	g++ -c DuarteL11app.cpp -g

Fraction.o : Fraction.cpp Fraction.h
	g++ -c Fraction.cpp -g

clean :
	rm -f core.* *.o L11.out

