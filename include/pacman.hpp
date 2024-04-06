#include <iostream>

namespace Game{
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class Pacman{
        private:
            int pos_x;
            int pos_y;
            int grid_height, grid_width;
            int color[3];
            Direction currentDirection;
        public:
            Pacman(int grid_height, int grid_width);
            void movePacman();
            void setDirection(Direction dirn);
            void renderPacman();
    };
}
