#include "include/utils.hpp"
#include <GL/freeglut_std.h>
#include <iostream>

namespace Game{
    void createWindow(char* title, int WIDTH, int HEIGHT){
        std::cout << "Creating Window" << std::endl;
        glutCreateWindow(title);
        glutInitWindowSize(WIDTH, HEIGHT);
    }

    // Pacman Object
    Pacman::Pacman(int grid_height, int grid_width){
        this->setDirection(Direction::RIGHT);
        pos_x = grid_width/2;
        pos_y = grid_height/2;
    }

    void Pacman::setDirection(Direction dirn){
        this->currentDirection = dirn;
    }

    void Pacman::renderPacman(){
        // OpenGL commands to draw a circle or load a pacman sprite
        std::cout << "TODO!" << std::endl;
    }

    void Pacman::movePacman(){
        std::cout << "TODO!" << std::endl;
    }
}
