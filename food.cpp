#include "include/pirahna.hpp"
#include "include/shapes.hpp"

namespace Game {
    Food::Food(int x_offset,int y_offset){
        this->pos_x = x_offset;
        this->pos_y = y_offset;
    }

    void Food::drawFood(){
        Circle::drawFood(this->pos_x,this->pos_y);
    }

    // void Food::checkCollisions(){

    // }
}
