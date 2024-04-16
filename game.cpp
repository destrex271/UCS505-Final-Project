#include "include/game.hpp"
#include <iostream>
#include <vector>

namespace Game{
    GameObject::GameObject(int screen_height, int screen_width){
        std::cout << "Created Game Session" << std::endl;
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        pacmanObj = new Pacman(screen_height, screen_width);
        ghostObj = new Ghost;
        gameOver = false;

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
        this->pacmanObj->movePacman();

        Ghost blinky = this->ghosts[0];
        std::vector<float> colors = blinky.getGhostColor();
        blinky.renderGhost(200, 0, 0, colors[0], colors[1], colors[2]);

    }

}
