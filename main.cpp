#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "include/utils.hpp"
#include <string>

void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background Color -> Black
    glClear(GL_COLOR_BUFFER_BIT);
    Game::drawGame();
    glBegin(GL_QUADS);
    glEnd();
    glFlush();
}

void init(){
    std::cout << "Initializing" << std::endl;
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-499.0, 500.0, -499.0, 500.0);
}

// Display a simple window
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::string title = "Pacman";
    
    //Third argument is for number of ghosts
    Game::GameObject* gameObj = new Game::GameObject(100, 100);
    Game::setGameObject(gameObj);

    Game::createWindow(title.data(), 300, 300);
    glutDisplayFunc(display);
    glutKeyboardFunc(Game::handleKeyboard);
    init();
    glutMainLoop();
    return 0;
}
