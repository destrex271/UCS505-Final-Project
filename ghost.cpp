#include "include/ghost.hpp"

namespace Game{
    
    Ghost::Ghost(){
        this->pointsIfEaten = 100;
        this->pos_x = 0;
        this->pos_y = 0;
        this->harmless = false;
        float temp[3] = {1.0, 0., 0.};
        color[0] = 1.; 
    }

    void Ghost::setHarmless(bool state){
        this->harmless = state;
        //setting a timer of ten seconds, not used right now
        this->timeLeftHarmless = 10;
    }

    void Ghost::moveGhost(int pos_x_pacman, int pos_y_pacman){
        //Will change in the future;
        int diff_x =  pos_x_pacman - this->pos_x;
        int diff_y = pos_y_pacman - this->pos_y;

        int step_x = abs(diff_x)/diff_x; 
        int step_y = abs(diff_y)/diff_y; 

        if(abs(diff_x) > abs(diff_y)) pos_x += step_x;
        else pos_y += step_y;
    }

    void Ghost::renderGhost(){

        std::cout << "TODO" << std::endl;
    }
}