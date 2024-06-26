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
            void checkCollisions();
    };


    class Net: public BoxObject{
            bool harmless;
            int timeLeftHarmless;
            int pointsIfEaten;
            float color[3];
            std::vector<int> direction;

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
            void setNetColor(float r, float g, float b);
            std::vector<float> getNetColor();
            void checkCollisions();
            int gen_rand(int lb, int ub);
            void setScreen(int width, int height);
    };

    class Food : public BoxObject{
        int x_offset;
        int y_offset;
        public:
            Food(int x_offset,int y_offset);
            void drawFood();
            // void checkCollisions();

    };
}
