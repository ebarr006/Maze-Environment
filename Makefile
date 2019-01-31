CC=g++
FLAGS= -g -Wall -Werror

start: main.o cell.o maze.o mouse.o stack.o
	$(CC) $(FLAGS) main.o cell.o maze.o mouse.o stack.o -o start

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

cell.o: cell.*
	$(CC) $(FLAGS) -c cell.cpp

maze.o: maze.*
	$(CC) $(FLAGS) -c maze.cpp

mouse.o: mouse.*
	$(CC) $(FLAGS) -c mouse.cpp

stack.o: stack.*
	$(CC) $(FLAGS) -c stack.cpp

clean:
	rm *.o start

# https://www.youtube.com/watch?v=_r7i5X0rXJk
# ffs