#include "include/utils.hpp"
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>

// Window related utility funcitons go here


namespace Game{
    int windowId;
    int createWindow(char* title, int WIDTH, int HEIGHT){
        std::cout << "Creating Window" << std::endl;
        windowId = glutCreateWindow(title);
        std::cout << "Created Window" << WIDTH << " " << HEIGHT << std::endl;
        glutInitWindowSize(WIDTH, HEIGHT);
        return windowId;
    }

    Game::GameObject* gameObject;

    void setGameObject(GameObject* gobj){
        gameObject = gobj;
    }

    void drawGame(){
        gameObject->renderGame();
    }

    // Handle keyboard events
    void handleKeyboard(unsigned char key, int mouseX, int mouseY){
        switch(key){
            case 'w':
            case 'W':
                std::cout << "UP" << std::endl;
                gameObject->displayData();
                gameObject->pirahnaObj->setDirection(Direction::UP);
                break;
            case 'a':
            case 'A':
                std::cout << "LEFT" << std::endl;
                gameObject->displayData();
                gameObject->pirahnaObj->setDirection(Direction::LEFT);
                break;
            case 'd':
            case 'D':
                std::cout << "RIGHT" << std::endl;
                gameObject->displayData();
                gameObject->pirahnaObj->setDirection(Direction::RIGHT);
                break;
            case 's':
            case 'S':
                std::cout << "DOWN" << std:: endl;
                gameObject->displayData();
                gameObject->pirahnaObj->setDirection(Direction::DOWN);
                break;
            case 'q':
            case 'Q':
                std::cout << "Exiting Game!" << std::endl;
                gameObject->displayData();
                quitGame();
                break;
            case 'r':
            case 'R':
                std::cout << "Restart Game!" << std::endl;
                if(gameObject->gameOver){
                    GameObject* j = new GameObject(500, 500, 1);
                    setGameObject(j);
                }
                break;
        }
    }

    void quitGame(){
        gameObject->gameOver = true;
        glutDestroyWindow(windowId);
    }

    

}
