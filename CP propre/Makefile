
all:prog

prog : main.o Problem.o Domain.o Constraint.o
	g++ -o prog main.o Problem.o Domain.o Constraint.o

Constraint.o : Constraint.cpp
	g++ -o Constraint.o -c Constraint.cpp -W -Wall

Domain.o : Domain.cpp
	g++ -o Domain.o -c Domain.cpp -W -Wall

Problem.o : Problem.cpp Domain.h Constraint.h
	g++ -o Problem.o -c Problem.cpp -W -Wall

main.o : main.cpp Problem.h Domain.h Constraint.h
	g++ -o main.o -c main.cpp -W -Wall

clean :
	rm -f *~ *.o

mrproper: clean
	rm -f prog
