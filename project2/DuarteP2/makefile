P2.out: DuarteP2app.o SetLimits.o CGame.o
	g++ -g -o P2.out  DuarteP2app.o SetLimits.o CGame.o

Proj2app.o:  DuarteP2app.cpp SetLimits.h CGame.h
	g++ -g -c  DuarteP2app.cpp

SetLimits.o: SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

CGame.o: CGame.cpp CGame.h
	g++ -g -c CGame.cpp

clean:
	rm *.o P2.out

run : P2.out
	clear
	./P2.out

runin : P2.out input
	clear
	./P2.out < input

submit :  DuarteP2app.cpp CGame.h CGame.cpp makefile README.txt
	rm -rf  DuarteP2
	mkdir  DuarteP2
	cp DuarteP2app.cpp  DuarteP2
	cp CGame.h  DuarteP2
	cp CGame.cpp  DuarteP2
	cp makefile  DuarteP2
	cp README.txt  DuarteP2
	tar cfvz DuarteP2.tgz  DuarteP2
	cp DuarteP2.tgz ~cs215/cs215drop
