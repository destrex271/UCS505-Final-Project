#include "include/pacman.hpp"
#include "include/shapes.hpp"
#include <iostream>

namespace Game{
    
    Ghost::Ghost(){
        acc_x=1;
        acc_y=1;
        pointsIfEaten = 100;
        pos_x = 450;
        pos_y = 450;
        size = 20;
        harmless = false;
        area_x = 30;
        area_y = 30;
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

    void Ghost::setAx(int acc_x){
        this->acc_x = acc_x;
    }

    void Ghost::setAy(int acc_y){
        this->acc_y = acc_y;
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

        std::cout << "diff: " << diff_x << " " << diff_y << std::endl;


        int step_x = acc_x*abs(diff_x)/(diff_x + 0.1); 
        int step_y = acc_y*abs(diff_y)/(diff_y + 0.1);
        std::cout << step_x << " " << step_y << std::endl;


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