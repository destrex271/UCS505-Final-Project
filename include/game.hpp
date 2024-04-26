#include "pirahna.hpp"

namespace Game{
    class GameObject{
        public:
            Pirahna* pirahnaObj;
            std::vector<Food> food;
            float water_del = 0.5;
            // Max Possible Size 300, 300
            int screen_height, screen_width, window_id;
            bool gameOver; // If true terminate everything
            GameObject(int screen_height, int screen_width, int window_id);
            void displayData();
            void renderGame();
            void gameOverScreen();
            void checkNetCollision();
            void quitWindow();
            std::pair<int, int> scaleToWindowDim(std::pair<int, int> screen_dim);
            void drawWorld();

            Net ghosts[4];
            int score;

            Food* khana = new Food(150,150);            

    };

    void drawGameGrid();

}
