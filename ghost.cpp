#include "include/ghost.hpp"
#include "include/shapes.hpp"
#include <iostream>

namespace Game{
    
    Ghost::Ghost(){
        this->pointsIfEaten = 100;
        this->pos_x = 450;
        this->pos_y = 450;
        this->size = 20;
        // std::cout << "Here" << std::endl;
        this->harmless = false;
        color[0] = 1.; 
        color[1] = 0.;
        color[2] = 0.;
    }

    void Ghost::setX(int x){
        this->pos_x = x;
    }

    void Ghost::setY(int y){
        this->pos_y = y;
    }

    int Ghost::getX(){
       return this->pos_x;
    }

    int Ghost::getY(){
        return this->pos_y;
    }

    void Ghost::setGhostColor(float r, float g, float b){
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    std::vector<float> Ghost::getGhostColor(){
        return {color[0], color[1], color[2]};
    }

    void Ghost::setHarmless(bool state){
        this->harmless = state;
        //setting a timer of ten seconds, not used right now
        this->timeLeftHarmless = 10;
    }

    void Ghost::moveGhost(int pos_x_pacman, int pos_y_pacman){
        //Might change in the future;
       
        // std::cout << "BEFORE" << std::endl;
        // std::cout << this->pos_x << " " << this->pos_y << std::endl;
        int diff_x =  pos_x_pacman - this->pos_x;
        int diff_y = pos_y_pacman - this->pos_y;


        int step_x = abs(diff_x)/diff_x; 
        int step_y = abs(diff_y)/diff_y;


        if(abs(diff_x) > abs(diff_y)) this->pos_x += step_x;
        else this->pos_y += step_y;
        // std::cout << "AFTER" << std::endl;
        // std::cout << this->pos_x << " " << this->pos_y << std::endl;
    }

    void Ghost::renderGhost(){

        // std::cout << "Drawing ghost..." << std::endl;

        Sprites::drawGhost(size, pos_x, pos_y, color[0], color[1], color[2]);
    }
}