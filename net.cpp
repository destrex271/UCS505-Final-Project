#include "include/pirahna.hpp"
#include "include/shapes.hpp"
#include <iostream>
#include <cstdlib>

namespace Game{
    
    Net::Net(){
        acc_x=4;
        acc_y=4;
        pointsIfEaten = 100;
        pos_x = 35;
        pos_y = 35;
        size = 15;
        harmless = false;
        area_x = 20;
        area_y = 20;
        color[0] = 1.; 
        color[1] = 0.;
        color[2] = 0.;
        direction = std::vector<int>(2, 0);
    }

    void Net::setScreen(int width, int height){
        this->screen_width = width;
        this->screen_height = height;
    }

    int Net::gen_rand(int lb, int ub){
        return (rand() % (ub - lb + 1)) + lb;
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

    void Net::moveNet(int pos_x_pacman, int pos_y_pacman){

        float num = (float)rand()/RAND_MAX;
        if (num > 0.8){
            int diff_x =  pos_x_pacman - this->pos_x;
            int diff_y = pos_y_pacman - this->pos_y;

            if(abs(diff_x) > abs(diff_y)){
                direction[0] = acc_x*abs(diff_x)/(diff_x + 0.1); 
                direction[1] = 0;
            } else{
                direction[0] = 0;
                direction[1] = acc_y;
            }

            this->pos_x += direction[0];
            this->pos_y += direction[1];
        }
        else if (num > 0.4){
            this->pos_x += direction[0];
            this->pos_y += direction[1];
        
        } else {
            int num_step_x = gen_rand(-1, 1);
            int num_step_y = gen_rand(-1, 1);
            this->pos_x += num_step_x;
            this->pos_y += num_step_y;
        };
        checkCollisions();
        
    }

    void Net::renderNet(){
        Sprites::drawNet(size, pos_x, pos_y, color[0], color[1], color[2]);
    }

    void Net::checkCollisions(){
        auto bound = hitBoundary();
        if (bound == Boundary::NONE) return;

        pos_x = gen_rand(area_x + size, screen_width - area_x - size);
        pos_y = area_y + size;
    }

}
