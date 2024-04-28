#include "include/game.hpp"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

#define NUM_GHOSTS 4

namespace Game{
    GameObject::GameObject(int screen_height, int screen_width, int window_id){
        std::cout << "Created Game Session" << std::endl;
        this->screen_width = screen_width;
        this->screen_height = screen_height;
        this->window_id = window_id;
        for(int i = 0; i < 6; i++){
            this->addFood();
        }
        auto khana = new Food(150,150);            
        pirahnaObj = new Pirahna(screen_height, screen_width);

        int ghost_x = this->ghosts[0].area_x;
        int ghost_y = this->ghosts[0].area_y;

        this->ghosts[1].setX(screen_width - ghost_x - 10);
        this->ghosts[1].setY(ghost_y + 10);

        this->ghosts[2].setX(ghost_x + 10);
        this->ghosts[2].setY(screen_height - ghost_y - 10);

        this->ghosts[3].setX(screen_width - ghost_x - 10);
        this->ghosts[3].setY(screen_height - ghost_y - 10);
        
        this->ghosts[1].setNetColor(1, 0.5, 0);
        this->ghosts[2].setNetColor(0, 1, 1);
        this->ghosts[3].setNetColor(1, 0.4, 0.4);

        gameOver = false;

        this->score = 0;
    }

    void GameObject::gameOverScreen(){
        glColor3f(1, 1, 1);
        std::string s = "Your Score Was: " + std::to_string(this->score);
        glRasterPos2f(250 - s.size(), 250);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
        }

        s = "Press 'r' to restart and 'q' to exit!";
        glRasterPos2f(250 - s.size() * 2, 270);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
        }

        s = "Game Over!";
        glRasterPos2f(250 - s.size() * 2, 280);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }

    void GameObject::drawWorld(){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 1, 1);
        std::string s = "Score is: " + std::to_string(this->score);
        glRasterPos2f(10,10);
        for(auto c: s){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
        this->water_del = -1;
        if(this->gameOver) return;
        for(int y = 10; y < this->screen_height; y+=30){
            for(int x = 10; x < this->screen_width; x+=30){
                glColor4f(0.3, 0.6, 1.0, 0.0);
                glBegin(GL_LINES);
                glVertex2f(x-4 - water_del, y - water_del);
                glVertex2f(x+4 + water_del, y + water_del);
                glEnd();
            }
        }
    }

    void GameObject::displayData(){
        std::cout << "===============================" << std::endl;
        std::cout << "Game Details: " << std::endl;
        std::cout << "\tGrid Width: " << screen_width << std::endl;
        std::cout << "\tGrid Height: " << screen_height << std::endl;
        std::cout << "\tGame Over: " << gameOver << std::endl;
        std::cout << "\tFood Left: " << this->food.size() << std::endl;
        std::cout << "===============================" << std::endl << std::endl;
    }

    std::pair<int, int> GameObject::scaleToWindowDim(std::pair<int, int> screen_dim){
        return {screen_dim.first / (1.0 * this->screen_width), screen_dim.second / (1.0 * this->screen_height)};
    }

    void GameObject::renderGame(){
        this->drawWorld();
        if(this->gameOver){
            this->gameOverScreen();
            return;
        }

        this->pirahnaObj->drawPirahna();
        this->pirahnaObj->movePirahna();

        for(auto item: this->food){
            if(item.second != nullptr)
                item.second->drawFood();    
        }

        for (int i = 0; i < NUM_GHOSTS; i++) this->ghosts[i].moveNet(this->pirahnaObj->pos_x, this->pirahnaObj->pos_y);
        
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
        
        for (int i = 0; i < NUM_GHOSTS; i++) this->ghosts[i].renderNet();

        this->checkFoodCollision();
        this->checkNetCollision();

        //function to update pellet counts
    }

    void GameObject::quitWindow(){
        glutDestroyWindow(this->window_id);
    }


    void GameObject::checkNetCollision(){
        for(auto ghost: this->ghosts){
            bool ok = this->pirahnaObj->isIntersecting(ghost);
            if(ok){
                this->gameOver = true;
            }
        }
    }

    void GameObject::checkFoodCollision(){
        bool addFood = false;
        for(auto pr: food){
            auto item = pr.second;
            if(item != nullptr && this->pirahnaObj->isIntersecting(*item)){
                this->score++;
                food[pr.first] = nullptr;
                std::cout << "New Score is: " << this->score << std::endl;
                addFood = true;
                break;
            }
        }
        if(addFood){
            this->addFood();
            this->cleanUp();
        }
    }

    void GameObject::addFood(){
        int x = rand()%(this->screen_width - 30 + 1);
        int y = rand()%(this->screen_height - 30  + 1);
        auto khana = new Food(x, y);
        this->food[{x, y}] = khana;
    }

    void GameObject::cleanUp(){
        std::vector<std::pair<int, int>> to_rem;
        for(auto entry: this->food){
            if(entry.second == nullptr){
                to_rem.push_back(entry.first);
            }
        }

        for(auto key: to_rem){
            this->food.erase(key);
        }
    }

}
