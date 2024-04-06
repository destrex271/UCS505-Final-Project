#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "include/utils.hpp"
#include <string>

void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background Color -> Black
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glEnd();
    glFlush();
}

// Display a simple window
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::string title = "Pacman";
    Game::createWindow(title.data(), 300, 300);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
