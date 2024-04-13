CC = g++
DFLAGS = -lglut -lGLU -lGL
INC_DIR = ./include


output: main.o utils.o pacman.o game.o shapes.o
	$(CC) main.o utils.o pacman.o game.o shapes.o -o output $(DFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp -I$(INC_DIR) $(DFLAGS)

utils.o: utils.cpp $(INC_DIR)/utils.hpp
	$(CC) -c utils.cpp -I$(INC_DIR) $(DFLAGS)

pacman.o: pacman.cpp $(INC_DIR)/pacman.hpp
	$(CC) -c pacman.cpp -I$(INC_DIR) $(DFLAGS)

ghost.o: ghost.cpp $(INC_DIR)/ghost.hpp
	$(CC) -c ghost.cpp -I$(INC_DIR) $(DFLAGS)

game.o: game.cpp $(INC_DIR)/game.hpp
	$(CC) -c game.cpp -I$(INC_DIR) $(DFLAGS)

shapes.o: shapes.cpp $(INC_DIR)/shapes.hpp
	$(CC) -c shapes.cpp -I$(INC_DIR) $(DFLAGS)

clean:
	rm -f *.o output
