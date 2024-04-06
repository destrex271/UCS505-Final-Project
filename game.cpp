#include "include/game.hpp"

namespace Game{
    GameObject::GameObject(int grid_height, int grid_width){
        std::cout << "Created Game Session" << std::endl;
        this->grid_width = grid_width;
        this->grid_height = grid_height;
        pacmanObj = new Pacman(grid_height, grid_width);
        gameOver = false;
    }

    void GameObject::displayData(){
        std::cout << "===============================" << std::endl;
        std::cout << "Game Details: " << std::endl;
        std::cout << "\tGrid Width: " << grid_width << std::endl;
        std::cout << "\tGrid Height: " << grid_height << std::endl;
        std::cout << "\tGame Over: " << gameOver << std::endl;
        std::cout << "===============================" << std::endl << std::endl;
    }
}
