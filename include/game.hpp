#include "pacman.hpp"
#include "ghost.hpp"

namespace Game{
    class GameObject{
        public:
            Pacman* pacmanObj;
            // Max Possible Size 300, 300
            int screen_height, screen_width;
            bool gameOver; // If true terminate everything
            GameObject(int screen_height, int screen_width);
            void displayData();
            void renderGame();
            std::pair<int, int> scaleToWindowDim(std::pair<int, int> screen_dim);

            Ghost ghosts[3];
            int score;
    };

    

    void drawGameGrid();
}
