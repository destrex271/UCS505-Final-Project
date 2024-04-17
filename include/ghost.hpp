#include <vector>

namespace Game{
    class Ghost{
            int pos_x, pos_y;
            int screen_height, screen_width;
            bool harmless;
            int timeLeftHarmless;
            int pointsIfEaten;
            float color[3];

        public:
            int size; 
            Ghost();
            void setX(int x);
            void setY(int y);
            int getX();
            int getY();
            void moveGhost(int pos_x_pacman, int pos_y_pacman);
            void renderGhost();
            void setHarmless(bool state);
            void setGhostColor(float r, float g, float b);
            std::vector<float> getGhostColor();
    };
}