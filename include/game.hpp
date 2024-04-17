#include "pacman.hpp"

namespace Game{
    class GameObject{
        public:
            Pacman* pacmanObj;
            // Max Possible Size 300, 300
            int screen_height, screen_width, window_id;
            bool gameOver; // If true terminate everything
            GameObject(int screen_height, int screen_width, int window_id);
            void displayData();
            void renderGame();
            void gameOverScreen();
            void checkGhostCollision();
            void quitWindow();
            std::pair<int, int> scaleToWindowDim(std::pair<int, int> screen_dim);

            Ghost ghosts[4];
            int score;
    };

    void drawGameGrid();

}
