COMPILE=g++
FLAGS=-Wall -Werror -ansi -pedantic
OBJS=cell.o maze.o
all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o program.out main.cpp $(OBJS)

cell.o: cell.cpp cell.h
	$(COMPILE) $(FLAGS) -c cell.cpp
maze.o: maze.cpp maze.h
	$(COMPILE) $(FLAGS) -c maze.cpp
clean:
	rm *.o program.out
