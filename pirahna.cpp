#include "include/pirahna.hpp"
#include <iostream>
#include "include/shapes.hpp"

#define PAC_ACC 5

namespace Game{
    // Pirhana Object
    Pirahna::Pirahna(int screen_height, int screen_width){
        this->setDirection(Direction::RIGHT);
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        this->pos_x = screen_width/2;
        this->pos_y = screen_height/2;
        std::cout << pos_x << " " << pos_y << std::endl;
        this->area_x = 30;
        this->area_y = 30;
    }

    void Pirahna::setDirection(Direction dirn){
        this->currentDirection = dirn;
        // std::cout << "Direction set to " << dirn << std::endl;
    }

    void Pirahna::drawPirahna(){
        // OpenGL commands to draw a circle or load a pacman sprite
        /* std::cout << "Drawing pacman: " << pos_x << " " << pos_y << std::endl; */
        switch(this->currentDirection){
            case Direction::RIGHT: {
                Circle::drawPacmanCircle(this->area_x - 10, pos_x, pos_y, 0);
                break;
            }
            case Direction::LEFT: {
                Circle::drawPacmanCircle(this->area_x - 10, pos_x, pos_y, 1);
                break;
            }
            case Direction::UP: {
                Circle::drawPacmanCircle(this->area_x - 10, pos_x, pos_y, 2);
                break;
            }
            case Direction::DOWN: {
                Circle::drawPacmanCircle(this->area_x - 10, pos_x, pos_y, 3);
            }
        }

    }

    void Pirahna::checkCollisions(){
        auto stat = this->hitBoundary();
        // std::cout << "Check stat: " << stat << std::endl;
        switch(stat){
            case Boundary::RSIDE:
                // std::cout << "HIT RIGHT BOUND" << std::endl;
                this->currentDirection = Direction::LEFT;
                break;
            case Boundary::LSIDE:
                // std::cout << "HIT LEFT BOUND" << std::endl;
                this->currentDirection = Direction::RIGHT;
                break;
            case Boundary::TOP:
                // std::cout << "HIT TOP BOUND" << std::endl;
                this->currentDirection = Direction::DOWN;
                break;
            case Boundary::BOTTOM:
                // std::cout << "HIT BOTTOM BOUND" << std::endl;
                this->currentDirection = Direction::UP;
                break;
            case Boundary::NONE:
                return;
        }

        /* std::cout << "IN CC: "; */
        /* std::cout << this->acc_x << " " << this->acc_y << std::endl; */
    }


    void Pirahna::movePirahna(){
        int accx = 0;
        int accy = 0;
        switch(currentDirection){
            case Direction::UP:
                this->acc_y = -PAC_ACC;
                this->acc_x = 0;
                break;
            case Direction::DOWN:
                this->acc_y = PAC_ACC;
                this->acc_x = 0;
                break;
            case Direction::LEFT:
                this->acc_y = 0;
                this->acc_x = -PAC_ACC;
                break;
            case Direction::RIGHT:
                this->acc_y = 0;
                this->acc_x = PAC_ACC;
                break;
        }

        // std::cout << "IN MOVE PACMAN: ";
        // std::cout << this->acc_x << " " << this->acc_y << std::endl;
        this->checkCollisions();

        // std::cout << "AFTER: IN MOVE PACMAN: ";
        // std::cout << this->acc_x << " " << this->acc_y << std::endl;
        this->pos_x += this->acc_x;
        this->pos_y += this->acc_y;
    }
}
