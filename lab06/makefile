L06.out : DuarteL06.o Lab06app.o
	g++ -o L06.out DuarteL06.o Lab06app.o

DuarteL06.o : DuarteL06.h DuarteL06.cpp
	g++ -g -c DuarteL06.cpp

Lab06app.o : DuarteL06.h Lab06app.cpp
	g++ -g -c Lab06app.cpp

clean :
	rm *.o L06.out
