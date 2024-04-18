#include "commons.hpp"
#include <vector>

namespace Game{
    
    class Pirahna: public BoxObject{
        public:
            int color[3];
            Pirahna(int screen_height, int screen_width);
            void movePirahna();
            void setDirection(Direction dirn);
            void drawPirahna();
    };

    class Food: public BoxObject{
        public:
            Food(int pos_x, int pos_y);
            void drawFood();
    };

    class Net: public BoxObject{
            bool harmless;
            int timeLeftHarmless;
            int pointsIfEaten;
            float color[3];

        public:
            int size; 
            Net();
            void setAx(int x);
            void setAy(int y);
            void setX(int x);
            void setY(int y);
            int getX();
            int getY();
            void moveNet(int pos_x_pacman, int pos_y_pacman);
            void renderNet();
            void setHarmless(bool state);
            void setNetColor(float r, float g, float b);
            std::vector<float> getNetColor();
    };
}
