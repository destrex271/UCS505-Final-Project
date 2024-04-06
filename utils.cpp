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
}
