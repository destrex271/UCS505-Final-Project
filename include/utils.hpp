#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "game.hpp"

namespace Game{
    // Window utility
    void createWindow(char* title, int WIDTH, int HEIGHT);
    void handleKeyboard(unsigned char key, int mouseX, int mouseY);
    void setGameObject(GameObject* gobj);
}
