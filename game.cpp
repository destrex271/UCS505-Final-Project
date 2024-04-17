#include "include/game.hpp"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>

#define NUM_GHOSTS 4

namespace Game{
    GameObject::GameObject(int screen_height, int screen_width, int window_id){
        std::cout << "Created Game Session" << std::endl;
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        this->window_id = window_id;
        pacmanObj = new Pacman(screen_height, screen_width);

        this->ghosts[1].setX(30);
        this->ghosts[1].setY(30);
        this->ghosts[1].setAx(1);
        this->ghosts[1].setAy(1);

        this->ghosts[1].setGhostColor(1, 0.5, 0);
        

        this->ghosts[2].setX(470);
        this->ghosts[2].setY(30);
        this->ghosts[2].setAx(2);
        this->ghosts[2].setAy(2);
        this->ghosts[2].setGhostColor(0, 1, 1);

        this->ghosts[3].setX(30);
        this->ghosts[3].setY(470);
        this->ghosts[3].setAx(2);
        this->ghosts[3].setAy(2);
        this->ghosts[3].setGhostColor(1, 0.4, 0.4);

        gameOver = false;

        this->score = 0;
    }

    void GameObject::gameOverScreen(){
        glColor3f(1, 1, 1);
        std::string s = "Game Over!";
        glRasterPos2f(250 - s.size(), 250);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
        }

        s = "Press 'r' to restart and 'q' to exit!";
        glRasterPos2f(250 - s.size() * 2, 270);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
        }
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
            this->gameOverScreen();
            return;
        }

        this->pacmanObj->drawPacman();
        this->pacmanObj->movePacman();

        for (int i = 0; i < NUM_GHOSTS; i++) this->ghosts[i].moveGhost(this->pacmanObj->pos_x, this->pacmanObj->pos_y);

        for (int i = 0; i < NUM_GHOSTS; i++){
            for (int j = i + 1; j < NUM_GHOSTS; j++){
                if (this->ghosts[i].isIntersecting(this->ghosts[j])){
                    ghosts[i].setX(ghosts[i].getX() - 10);
                    ghosts[i].setY(ghosts[i].getY() - 10);
                    ghosts[j].setX(ghosts[j].getX() + 10);
                    ghosts[j].setY(ghosts[j].getY() + 10);
                }
            }
        }

        for (int i = 0; i < NUM_GHOSTS; i++) this->ghosts[i].renderGhost();
        


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
