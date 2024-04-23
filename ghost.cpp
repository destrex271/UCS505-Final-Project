#include "include/pirahna.hpp"
#include "include/shapes.hpp"
#include <iostream>

namespace Game{
    
    Net::Net(){
        acc_x=1;
        acc_y=1;
        pointsIfEaten = 100;
        pos_x = 470;
        pos_y = 470;
        size = 15;
        harmless = false;
        area_x = 20;
        area_y = 20;
        color[0] = 1.; 
        color[1] = 0.;
        color[2] = 0.;
    }

    void Net::setX(int x){
        this->pos_x = x;
    }

    void Net::setY(int y){
        this->pos_y = y;
    }

    int Net::getX(){
       return this->pos_x;
    }

    int Net::getY(){
        return this->pos_y;
    }

    void Net::setAx(int acc_x){
        this->acc_x = acc_x;
    }

    void Net::setAy(int acc_y){
        this->acc_y = acc_y;
    }
    void Net::setNetColor(float r, float g, float b){
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    std::vector<float> Net::getNetColor(){
        return {color[0], color[1], color[2]};
    }

    void Net::setHarmless(bool state){
        this->harmless = state;
        //setting a timer of ten seconds, not used right now
        this->timeLeftHarmless = 10;
    }

    void Net::moveNet(int pos_x_pacman, int pos_y_pacman){
        //Might change in the future;
       
        // std::cout << "BEFORE" << std::endl;
        // std::cout << this->pos_x << " " << this->pos_y << std::endl;
        int diff_x =  pos_x_pacman - this->pos_x;
        int diff_y = pos_y_pacman - this->pos_y;



        int step_x = acc_x*abs(diff_x)/(diff_x + 0.1); 
        int step_y = acc_y*abs(diff_y)/(diff_y + 0.1);


        if(abs(diff_x) > abs(diff_y)) this->pos_x += step_x;
        else this->pos_y += step_y;
        // std::cout << "AFTER" << std::endl;
        // std::cout << this->pos_x << " " << this->pos_y << std::endl;
    }

    void Net::renderNet(){

        // std::cout << "Drawing ghost..." << std::endl;

        Sprites::drawNet(size, pos_x, pos_y, color[0], color[1], color[2]);
    }

}
