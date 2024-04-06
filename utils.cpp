#include "include/utils.hpp"
#include <GL/freeglut_std.h>
#include <iostream>

// Window related utility funcitons go here


namespace Game{
    void createWindow(char* title, int WIDTH, int HEIGHT){
        std::cout << "Creating Window" << std::endl;
        glutCreateWindow(title);
        glutInitWindowSize(WIDTH, HEIGHT);
    }

    Game::GameObject* gameObject;

    void setGameObject(GameObject* gobj){
        gameObject = gobj;
    }

    // Handle keyboard events
    void handleKeyboard(unsigned char key, int mouseX, int mouseY){
        switch(key){
            case 'w':
            case 'W':
                std::cout << "UP" << std::endl;
                gameObject->displayData();
                gameObject->pacmanObj->setDirection(Direction::UP);
                break;
            case 'a':
            case 'A':
                std::cout << "LEFT" << std::endl;
                gameObject->displayData();
                gameObject->pacmanObj->setDirection(Direction::LEFT);
                break;
            case 'd':
            case 'D':
                std::cout << "RIGHT" << std::endl;
                gameObject->displayData();
                gameObject->pacmanObj->setDirection(Direction::RIGHT);
                break;
            case 's':
            case 'S':
                std::cout << "DOWN" << std:: endl;
                gameObject->displayData();
                gameObject->pacmanObj->setDirection(Direction::DOWN);
                break;
        }
    }
}
