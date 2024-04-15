#include "include/commons.hpp"

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
        if(this->pos_x - area_x <= 0) return Boundary::LSIDE;
        else if(this->pos_x + area_x >= screen_width) return Boundary::RSIDE;
        else if(this->pos_y - area_y <= 0) return Boundary::TOP;
        else if(this->pos_y + area_y >= screen_height) return Boundary::BOTTOM;
        return Boundary::NONE;
    }
}
