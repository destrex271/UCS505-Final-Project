#include "include/game.hpp"

namespace Game{
    GameObject::GameObject(int screen_height, int screen_width, int num = 1){
        std::cout << "Created Game Session" << std::endl;
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        pacmanObj = new Pacman(screen_height, screen_width);
        gameOver = false;

        this->num_ghosts = num;
        /* Ghost * ghosts = new Ghost[num_ghosts]; */
        this->score = 0;
    }

    void GameObject::displayData(){
        std::cout << "===============================" << std::endl;
        std::cout << "Game Details: " << std::endl;
        std::cout << "\tGrid Width: " << screen_width << std::endl;
        std::cout << "\tGrid Height: " << screen_height << std::endl;
        std::cout << "\tGame Over: " << gameOver << std::endl;
        std::cout << "===============================" << std::endl << std::endl;
    }

    std::pair<int, int> GameObject::scaleToWindowDim(std::pair<int, int> screen_dim){
        return {screen_dim.first / (1.0 * this->screen_width), screen_dim.second / (1.0 * this->screen_height)};
    }

    void GameObject::renderGame(){
        this->pacmanObj->drawPacman();
    }

}
