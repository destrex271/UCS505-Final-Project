#include <iostream>

namespace Game{
    class Pellet {
    private:
        int pos_x;
        int pos_y;
        bool isEaten;

    public:
        Pellet(int x, int y);
        void setEaten(bool eaten);
        bool getEaten();
        void renderPellet();
    };
}