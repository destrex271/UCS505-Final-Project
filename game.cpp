#include "include/game.hpp"

namespace Game{
    GameObject::GameObject(int grid_height, int grid_width){
        std::cout << "Created Game Session" << std::endl;
        this->grid_width = grid_width;
        this->grid_height = grid_height;
        pacmanObj = new Pacman(grid_height, grid_width);
        gameOver = false;

        // Initialize game grid
        for(int i = 0; i < this->grid_height; i++){
            std::cout << i << std::endl;
            std::vector<int> k;
            for(int j = 0; j < this->grid_width; j++){
                std::cout << j << std:: endl;
                k.push_back(0);
            }
            this->grid.push_back(k);
        }
    }

    void GameObject::displayData(){
        std::cout << "===============================" << std::endl;
        std::cout << "Game Details: " << std::endl;
        std::cout << "\tGrid Width: " << grid_width << std::endl;
        std::cout << "\tGrid Height: " << grid_height << std::endl;
        std::cout << "\tGame Over: " << gameOver << std::endl;
        std::cout << "===============================" << std::endl << std::endl;
    }

    std::pair<int, int> GameObject::scaleToWindowDim(std::pair<int, int> screen_dim){
        return {screen_dim.first / (1.0 * this->grid_width), screen_dim.second / (1.0 * this->grid_height)};
    }

    void drawGameGrid(){}
}
