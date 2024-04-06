CC = g++
DFLAGS = -lglut -lGLU -lGL

output: main.o utils.o
	$(CC) main.o utils.o -o output $(DFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(DFLAGS)

utils.o: utils.cpp ./include/utils.hpp
	$(CC) -c utils.cpp $(DFLAGS)

clean:
	rm *.o
