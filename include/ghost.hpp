#include <iostream>

namespace Game{
    class Ghost{
        private:
            int pos_x, pos_y;
            int screen_height, screen_width;
            float color[3];
            bool harmless;
            int timeLeftHarmless;
            int pointsIfEaten;

        public:
            Ghost();
            void moveGhost(int pos_x_pacman, int pos_y_pacman);
            void renderGhost();
            void setHarmless(bool state);
    };
}