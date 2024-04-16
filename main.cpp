#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "include/utils.hpp"
#include <string>

#define TIMER_DELAY 3

void animate(int v){
    glutPostRedisplay();
}

void display(){
    glutTimerFunc(TIMER_DELAY, animate, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background Color -> Black
    glClear(GL_COLOR_BUFFER_BIT);
    Game::drawGame();
    glFlush();
}

void init(){
    std::cout << "Initializing" << std::endl;
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500.0, 500, 0);
}

// Display a simple window
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::string title = "Pacman";
    

    Game::GameObject* gameObj = new Game::GameObject(500, 500, 1);

    Game::setGameObject(gameObj);

    Game::createWindow(title.data(), 300, 300);
    glutDisplayFunc(display);
    glutKeyboardFunc(Game::handleKeyboard);
    init();
    glutTimerFunc(1, animate, 0);
    glutMainLoop();
    return 0;
}
