#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "include/utils.hpp"
#include <string>
#include <iostream>

#define TIMER_DELAY 20

#define GAME_WIDTH 600
#define GAME_HEIGHT 600

void animate(int v){
    glutPostRedisplay();
}

void display(){
    glutTimerFunc(TIMER_DELAY, animate, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background Color -> Black
    Game::drawGame();
    glFlush();
}

void init(){
    std::cout << "Initializing" << std::endl;
    glClearColor(0.0, 0.0, 0.0, 1.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, GAME_WIDTH, GAME_HEIGHT, 0);
}

// Display a simple window
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::string title = "Piranha Escape";
    

    int id = Game::createWindow(title.data(), GAME_WIDTH, GAME_HEIGHT);
    Game::GameObject* gameObj = new Game::GameObject(GAME_WIDTH, GAME_HEIGHT, id);

    Game::setGameObject(gameObj);

    glutDisplayFunc(display);
    glutKeyboardFunc(Game::handleKeyboard);
    init();
    glutMainLoop();
    return 0;
}
