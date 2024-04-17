#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "include/utils.hpp"
#include <string>
#include <iostream>

#define TIMER_DELAY 10

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
	gluOrtho2D(0, 500.0, 500., 0);
}

// Display a simple window
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::string title = "Pacman";
    

    int id = Game::createWindow(title.data(), 500, 500);
    Game::GameObject* gameObj = new Game::GameObject(500, 500, id);
    gameObj->ghosts[1].setX(30);
    gameObj->ghosts[1].setY(30);
    gameObj->ghosts[1].setAx(1);
    gameObj->ghosts[1].setAy(1);

    gameObj->ghosts[1].setGhostColor(1, 0.5, 0);
    

    gameObj->ghosts[2].setX(470);
    gameObj->ghosts[2].setY(30);
    gameObj->ghosts[2].setAx(2);
    gameObj->ghosts[2].setAy(2);
    gameObj->ghosts[2].setGhostColor(0, 1, 1);

    gameObj->ghosts[3].setX(30);
    gameObj->ghosts[3].setY(470);
    gameObj->ghosts[3].setAx(2);
    gameObj->ghosts[3].setAy(2);
    gameObj->ghosts[3].setGhostColor(1, 0.4, 0.4);



    Game::setGameObject(gameObj);

    glutDisplayFunc(display);
    glutKeyboardFunc(Game::handleKeyboard);
    init();
    // glutTimerFunc(1, animate, 0);
    glutMainLoop();
    return 0;
}
