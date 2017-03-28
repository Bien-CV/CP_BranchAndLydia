OPTIONS = -std=c99 -ggdb

all: cpc

cpc : main.o pile.o Problem.o Domain.o pile_Dom.o Constraint.o
	$(CC) $(OPTIONS) -o cpc main.o pile.o pile_Dom.o Problem.o Domain.o Constraint.o

pile.o: pile.c
	$(CC) $(OPTIONS) -o pile.o -c pile.c -W -Wall

pile_Dom.o: pile_Dom.c Domain.h
	$(CC) $(OPTIONS) -o pile_Dom.o -c pile_Dom.c -W -Wall

Constraint.o : Constraint.c
	$(CC) $(OPTIONS) -o Constraint.o -c Constraint.c -W -Wall

Domain.o : Domain.c pile.h
	$(CC) $(OPTIONS) -o Domain.o -c Domain.c -W -Wall

Problem.o : Problem.c Domain.h Constraint.h
	$(CC) $(OPTIONS) -o Problem.o -c Problem.c -W -Wall

main.o : main.c Problem.h Domain.h Constraint.h pile.h pile_Dom.h
	$(CC) $(OPTIONS) -o main.o -c main.c -W -Wall

clean :
	rm -f *~ *.o

mrproper: clean
	rm -f cpc
