#include "pacman.hpp"
#include <vector>

namespace Game{
    class GameObject{
        public:
            Pacman* pacmanObj;
            int grid_height, grid_width;
            std::vector<std::vector<int>> grid;
            bool gameOver; // If true terminate everything
            GameObject(int grid_height, int grid_width);
            void displayData();
            std::pair<int, int> scaleToWindowDim(std::pair<int, int> screen_dim);
    };

    void drawGameGrid();
}
