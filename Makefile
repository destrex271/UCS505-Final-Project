CC = g++
DFLAGS = -lglut -lGLU -lGL
INC_DIR = ./include


output: main.o utils.o pirahna.o game.o shapes.o commons.o food.o net.o
	$(CC) main.o utils.o pirahna.o game.o shapes.o food.o net.o commons.o -o output $(DFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp -I$(INC_DIR) $(DFLAGS)

utils.o: utils.cpp $(INC_DIR)/utils.hpp
	$(CC) -c utils.cpp -I$(INC_DIR) $(DFLAGS)

pirahna.o: pirahna.cpp $(INC_DIR)/pirahna.hpp
	$(CC) -c pirahna.cpp -I$(INC_DIR) $(DFLAGS)

net.o: net.cpp $(INC_DIR)/pirahna.hpp
	$(CC) -c net.cpp -I$(INC_DIR) $(DFLAGS)

game.o: game.cpp $(INC_DIR)/game.hpp
	$(CC) -c game.cpp -I$(INC_DIR) $(DFLAGS)

shapes.o: shapes.cpp $(INC_DIR)/shapes.hpp
	$(CC) -c shapes.cpp -I$(INC_DIR) $(DFLAGS)


commons.o: commons.cpp $(INC_DIR)/commons.hpp
	$(CC) -c commons.cpp -I$(INC_DIR) $(DFLAGS)

food.o: food.cpp $(INC_DIR)/pirahna.hpp
	$(CC) -c food.cpp -I$(INC_DIR) $(DFLAGS)


clean:
	rm -f *.o output
