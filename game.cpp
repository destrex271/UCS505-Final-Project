#include "include/game.hpp"
#include <iostream>
#include <GL/glut.h>

namespace Game{
    GameObject::GameObject(int screen_height, int screen_width, int window_id){
        std::cout << "Created Game Session" << std::endl;
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        this->window_id = window_id;
        pacmanObj = new Pacman(screen_height, screen_width);
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
        if(this->gameOver){
            quitWindow();
            return;
        }

        this->pacmanObj->drawPacman();
        this->pacmanObj->movePacman();

        this->ghosts[0].renderGhost();
        this->ghosts[0].moveGhost(this->pacmanObj->pos_x, this->pacmanObj->pos_y);

        this->ghosts[1].renderGhost();
        this->ghosts[1].moveGhost(this->pacmanObj->pos_x, this->pacmanObj->pos_y);

        this->ghosts[2].renderGhost();
        this->ghosts[2].moveGhost(this->pacmanObj->pos_x, this->pacmanObj->pos_y);

        this->ghosts[3].renderGhost();
        this->ghosts[3].moveGhost(this->pacmanObj->pos_x, this->pacmanObj->pos_y);

        this->checkGhostCollision();
    }

    void GameObject::quitWindow(){
        glutDestroyWindow(this->window_id);
    }

    void GameObject::checkGhostCollision(){
        for(auto ghost: this->ghosts){
            bool ok = this->pacmanObj->isIntersecting(ghost);
            if(ok){
                this->gameOver = true;
            }
        }
    }

}
