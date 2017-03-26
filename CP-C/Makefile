
all: cpc

cpc : main.o pile.o pile_Dom.o Problem.o Domain.o Constraint.o
	$(CC) -o cpc main.o pile.o pile_Dom.o Problem.o Domain.o Constraint.o

pile.o: pile.c
	$(CC) -o pile.o -c pile.c -W -Wall
	
pile_Dom.o: pile_Dom.c
	$(CC) -o pile_Dom.o -c pile_Dom.c -W -Wall

Constraint.o : Constraint.c
	$(CC) -o Constraint.o -c Constraint.c -W -Wall

Domain.o : Domain.c pile.h
	$(CC) -o Domain.o -c Domain.c -W -Wall

Problem.o : Problem.c Domain.h Constraint.h
	$(CC) -o Problem.o -c Problem.c -W -Wall

main.o : main.c Problem.h Domain.h Constraint.h pile.h
	$(CC) -o main.o -c main.c -W -Wall

clean :
	rm -f *~ *.o

mrproper: clean
	rm -f cpc
