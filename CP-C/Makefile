
all: cpc

cpc : main.o Problem.o Domain.o Constraint.o
	$(CC) -o cpc main.o Problem.o Domain.o Constraint.o

Constraint.o : Constraint.c
	$(CC) -o Constraint.o -c Constraint.cpp -W -Wall

Domain.o : Domain.c
	$(CC) -o Domain.o -c Domain.cpp -W -Wall

Problem.o : Problem.c Domain.h Constraint.h
	$(CC) -o Problem.o -c Problem.cpp -W -Wall

main.o : main.c Problem.h Domain.h Constraint.h
	$(CC) -o main.o -c main.c -W -Wall

clean :
	rm -f *~ *.o

mrproper: clean
	rm -f prog
