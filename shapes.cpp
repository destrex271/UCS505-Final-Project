#include "include/shapes.hpp"
#include <iostream>

namespace Game{
    std::vector<int> Circle::calc_d_MidPoint(int pi, int x, int y){
        int new_pi;
        int new_y;
        int new_x;
        if(pi <= 0){
            new_pi = pi + 2 * x + 3;
            new_x = x + 1;
            new_y = y;
        }else{
            new_pi = pi + 2 * (x - y) + 5;
            new_x = x + 1;
            new_y = y - 1;
        }
        return {new_pi, new_x, new_y};
    }

    void drawPoint(int x, int y){
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
    }

    void Line::drawLineDDA(int x1, int x2, int y1, int y2){
        int slope = (y2 - y1)/(x2 - x1);
        glPointSize(1.0);
        int c = y1 - slope*x1;
        while(x1 != x2 && y1 != y2){
            drawPoint(x1, y1);
            x1 = x1 + 1;
            y1 = slope * x1 + c;
        }
        glFlush();
    }

    void Circle::drawCircle(int radius, int x_offset, int y_offset){
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        int y = radius, x = 0, pi = (5/4.0) - y;
        while(x <= y){
            // Draw points
            glColor3f(1.0f, 1.0f, 1.0f);
            drawPoint(x, y);
            drawPoint(x, -y);
            drawPoint(-x, y);
            drawPoint(-x, -y);
            drawPoint(y, x);
            drawPoint(y, -x);
            drawPoint(-y, x);
            drawPoint(-y, -x);

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }
        glFlush();

    }

    void Circle::drawPacmanCircle(int radius, int x_offset, int y_offset){
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        int y = radius, x = 0, pi = (5/4.0) - y;
        while(x <= y){
            // Draw points
            glColor3f(1.0f, 1.0f, 1.0f);
            drawPoint(x, y);
            drawPoint(x, -y);
            drawPoint(-x, y);
            drawPoint(-x, -y);
            drawPoint(y, x);
            drawPoint(y, -x);
            

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }
        Line::drawLineDDA(-y, x_offset, x, y_offset);
        Line::drawLineDDA(-y, x_offset, -x, y_offset);
        glFlush();
    }
}
