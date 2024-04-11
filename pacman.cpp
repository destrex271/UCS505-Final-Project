#include "include/pacman.hpp"

namespace Game{
    // Pacman Object
    Pacman::Pacman(int screen_height, int screen_width){
        this->setDirection(Direction::RIGHT);
        pos_x = screen_width/2;
        pos_y = screen_height/2;
    }

    void Pacman::setDirection(Direction dirn){
        this->currentDirection = dirn;
        std::cout << "Direction set to " << dirn << std::endl;
    }

    void Pacman::renderPacman(){
        // OpenGL commands to draw a circle or load a pacman sprite
        std::cout << "TODO!" << std::endl;
    }

    void Pacman::movePacman(){
        int accx = 0;
        int accy = 0;
        switch(currentDirection){
            case UP:
                accy = -1;
                accx = 0;
                break;
            case DOWN:
                accy = 1;
                accx = 0;
                break;
            case LEFT:
                accx = -1;
                accy = 0;
                break;
            case RIGHT:
                accx = 1;
                accy = 0;
                break;
        }
        this->pos_x += accx;
        this->pos_y += accy;
    }
}
