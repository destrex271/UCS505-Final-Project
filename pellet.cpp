#include "include/pellet.hpp"

namespace Game {
    Pellet::Pellet(int x, int y){
        // set radius and other stuff of the pellet
        pos_x = x;
        pos_y = y;
        isEaten = false;
    }

    void Pellet::setEaten(bool eaten) {
        isEaten = eaten;
    }

    bool Pellet::getEaten() {
        return isEaten;
    }

    void Pellet::renderPellet() {
        std::cout << "Todo: Render Pellet";
    }
}