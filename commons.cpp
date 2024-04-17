#include "include/commons.hpp"
#include <iostream>

namespace Game{
    bool BoxObject::isIntersecting(BoxObject const& box2){
        if(this->pos_x - this->area_x <= box2.pos_x && this->pos_x + this->area_x >= box2.pos_x){
            if(this->pos_y - this->area_y <= box2.pos_y && this->pos_y + this->area_y >= box2.pos_y){
                return true;
            }
        }else if(box2.pos_x - box2.area_x <= this->pos_x && box2.pos_x + box2.area_x >= this->pos_x){
            if(box2.pos_y - box2.area_y <= this->pos_y && box2.pos_y - box2.area_y >= this->pos_y){
                return true;
            }
        }
        return false;
    }

    Boundary BoxObject::hitBoundary(){
        // std::cout << "Current X-Left: " << this->pos_x - area_x << "Current X-Right: " << this->pos_x + area_x << std::endl;
        // std::cout << "Current Y-TOP: " << this->pos_y - area_y << "Current Y-Bottom: " << this->pos_y + area_y << std::endl;
        // std::cout << "Screen width: " << this->screen_width << "Screen Height: " << this->screen_height << std::endl;
        if(this->pos_x - area_x <= 0){
            std::cout << "Hit left" << std::endl;
            return Boundary::LSIDE;
        }else if(this->pos_x + area_x >= screen_width) {
            std::cout << "Hit Right" << std::endl;
            return Boundary::RSIDE;
        } else if(this->pos_y - area_y <= 0) {
            std::cout << "Hit top" << std::endl;
            return Boundary::TOP;
        }else if(this->pos_y + area_y >= screen_height) {
            std::cout << "Hit bottom" << std::endl;
            return Boundary::BOTTOM;
        }
        return Boundary::NONE;
    }

    void BoxObject::checkCollisions(){
        auto stat = this->hitBoundary();
        // std::cout << "Check stat: " << stat << std::endl;
        switch(stat){
            case Boundary::RSIDE:
                std::cout << "HIT RIGHT BOUND" << std::endl;
                this->currentDirection = Direction::LEFT;
                break;
            case Boundary::LSIDE:
                std::cout << "HIT LEFT BOUND" << std::endl;
                this->currentDirection = Direction::RIGHT;
                break;
            case Boundary::TOP:
                std::cout << "HIT TOP BOUND" << std::endl;
                this->currentDirection = Direction::DOWN;
                break;
            case Boundary::BOTTOM:
                std::cout << "HIT BOTTOM BOUND" << std::endl;
                this->currentDirection = Direction::UP;
                break;
            case Boundary::NONE:
                return;
        }

        std::cout << "IN CC: ";
        std::cout << this->acc_x << " " << this->acc_y << std::endl;
    }
}
