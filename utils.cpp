#include "include/utils.hpp"
#include <GL/freeglut_std.h>
#include <iostream>

namespace Pacman{
    void createWindow(char* title, int WIDTH, int HEIGHT){
        std::cout << "Creating Window" << std::endl;
        glutCreateWindow(title);
        glutInitWindowSize(WIDTH, HEIGHT);
    }
}
