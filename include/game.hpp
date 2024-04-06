#include "pacman.hpp"

namespace Game{
    class GameObject{
        public:
            Pacman* pacmanObj;
            int grid_height, grid_width;
            bool gameOver; // If true terminate everything
            GameObject(int grid_height, int grid_width);
            void displayData();
    };
}
