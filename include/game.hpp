#include "pirahna.hpp"
#include "map"

namespace Game{
    class GameObject{
        public:
            Pirahna* pirahnaObj;
            std::map<std::pair<int, int>, Food*> food;
            float water_del = 0.5;
            // Max Possible Size 300, 300
            int screen_height, screen_width, window_id;
            bool gameOver; // If true terminate everything
            GameObject(int screen_height, int screen_width, int window_id);
            void displayData();
            void renderGame();
            void gameOverScreen();
            void checkNetCollision();
            void checkFoodCollision();
            void cleanUp();
            void addFood();
            void quitWindow();
            std::pair<int, int> scaleToWindowDim(std::pair<int, int> screen_dim);
            void drawWorld();

            Net ghosts[4];
            int score;


    };

    void drawGameGrid();

}
