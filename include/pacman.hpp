#include "commons.hpp"
#include <vector>

namespace Game{
    
    class Pacman: public BoxObject{
        public:
            int color[3];
            Pacman(int screen_height, int screen_width);
            void movePacman();
            void setDirection(Direction dirn);
            void drawPacman();
    };

    class Ghost: public BoxObject{
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
