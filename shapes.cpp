#include "include/shapes.hpp"
#include "math.h"
#include <GL/gl.h>
#include <algorithm>
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

    void drawPoints(std::vector<std::pair<int, int>>& points){
        glPointSize(1.0);
        glBegin(GL_TRIANGLE_FAN);
        for(auto point: points){
            glVertex2f(point.first, point.second);
        }
        glEnd();
    }

    void drawPolygon(std::vector<std::pair<int, int>> points){
        glPointSize(1.0);
        glBegin(GL_POLYGON);
        for(auto point: points){
            glVertex2f(point.first, point.second);
        }
        glEnd();
        glFlush();
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
    void Line::drawLineHorizontal(int x1, int x2, int y, float r, float g, float b){
        // glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        glColor3f(r, g, b);
        
        if (x2 < x1){
            int temp = x2;
            x2 = x1;
            x1 = temp;
        }

        for (int x = x1; x <= x2; x++) drawPoint(x, y);
        
        glFlush();
    }

    void Line::drawLineVertical(int x, int y1, int y2, float r, float g, float b){
        // glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        glColor3f(r, g, b);
        
        if (y2 < y1){
            int temp = y2;
            y2 = y1;
            y1 = temp;
        }

        for (int y = y1; y <= y2; y++) drawPoint(x, y);
        
        glFlush();
    }


    void Circle::drawCircle(int radius, int x_offset, int y_offset){
        /* glClear(GL_COLOR_BUFFER_BIT); */
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

    std::vector<std::pair<int, int>> Line::getLinePointsDDA(int x1, int x2, int y1, int y2){
        int slope = (y2 - y1)/(x2 - x1);
        int c = y1 - slope*x1;
        std::vector<std::pair<int, int>> points;
        while(x1 != x2 && y1 != y2){
            points.push_back({x1, y1});
            x1 = x1 + 1;
            y1 = slope * x1 + c;
        }
        return points;
    }

    void Circle::drawPacmanCircle(int radius, int x_offset, int y_offset,  int dirn){
        /* glClear(GL_COLOR_BUFFER_BIT); */
        int y = radius, x = 0, pi = (5/4.0) - y;
        std::vector<std::pair<int, int>> points;
        while(x <= y){
            // Draw points
            glColor3f(0.3, 0.9, 0.4);
            switch(dirn){
                case 1: { // RIGHT FACE
                    points.push_back({x + x_offset, y + y_offset});
                    points.push_back({x + x_offset, -y + y_offset});
                    points.push_back({-x + x_offset, y + y_offset});
                    points.push_back({-x + x_offset, -y + y_offset});
                    points.push_back({y + x_offset, x + y_offset});
                    points.push_back({y + x_offset, -x + y_offset});
                    break;
                }
                case 0: { // LEFT FACE
                    points.push_back({x + x_offset, y + y_offset});
                    points.push_back({x + x_offset, -y + y_offset});
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    points.push_back({-x + x_offset, y + y_offset});
                    points.push_back({-x + x_offset, -y + y_offset});
                    break;
                }
                case 2:{
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    points.push_back({x + x_offset, y + y_offset});
                    points.push_back({-x + x_offset, y + y_offset});
                    points.push_back({y + x_offset, x + y_offset});
                    points.push_back({y + x_offset, -x + y_offset});
                    break;
                }
                case 3:{
                    points.push_back({x + x_offset, -y + y_offset});
                    points.push_back({-x + x_offset, -y + y_offset});
                    points.push_back({y + x_offset, x + y_offset});
                    points.push_back({y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    break;
                }
            }

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }

        drawPoints(points);

        switch(dirn){
            case 0:{
                // std::cout << "LINE!" << std::endls
                glBegin(GL_TRIANGLES);
                glPointSize(10);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2f(y+x_offset+5, x+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(y+x_offset+5, -x+y_offset);
                glEnd();
                break;
            }
            case 1:{
                glBegin(GL_TRIANGLES);
                glPointSize(10);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2f(-y+x_offset-5, x+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-y+x_offset-5, -x+y_offset);
                glEnd();
                break;
            }
            case 2:{
                glBegin(GL_TRIANGLES);
                glPointSize(10);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-x+x_offset, -y+y_offset-5);
                glVertex2f(x+x_offset, -y+y_offset+-5);
                glEnd();
                break;
            }
            case 3:{
                glBegin(GL_TRIANGLES);
                glPointSize(10);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2f(x+x_offset, y+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-x+x_offset, y+y_offset);
                glEnd();
                break;
            }
        }

        glFlush();
    }

    void Sprites::drawNet(int radius, int h, int k, float r, float g, float b){
        //h and k represent the position of the sprite, radius represents the size of the sprite.

        glPointSize(1.0);
        glColor3f(r, g, b);

        // int y = radius, x = 0, pi = (5/4.0) - y;
        // while(x <= y){
        //     drawPoint(-x + h, -y + k);
        //     drawPoint(x + h, -y + k);
        //     drawPoint(-y + h, -x + k);
        //     drawPoint(y + h, -x + k);

        //     std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
        //     pi = coords[0];
        //     x = coords[1];
        //     y = coords[2];
        // }

        Line::drawLineVertical(radius + h, -radius + k, radius + k, r, g, b);
        Line::drawLineHorizontal(radius + h, -radius + h, radius + k, r, g, b);
        Line::drawLineVertical(0 + h, -radius + k, radius + k, r, g, b);
        Line::drawLineHorizontal(radius + h, -radius + h, 0 + k, r, g, b);
        Line::drawLineHorizontal(radius + h, -radius + h, -radius + k, r, g, b);
        Line::drawLineVertical(-radius + h, -radius + k, radius + k, r, g, b);
        
        glFlush();
    }

            void Circle::drawFood(int x_offset, int y_offset){
        // glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.5, 0.25, 0.25);
        glPointSize(2.0);
        int y = 7, x = 0, pi = (5/4.0) - y;
        while(x <= y){
            // Draw points
            glColor3f(1.0f, 1.0f, 1.0f);
            drawPoint(x+x_offset, y+y_offset);
            drawPoint(x+x_offset, -y+y_offset);
            drawPoint(-x+x_offset, y+y_offset);
            drawPoint(-x+x_offset, -y+y_offset);
            drawPoint(y+x_offset, x+y_offset);
            drawPoint(y+x_offset, -x+y_offset);
            drawPoint(-y+x_offset, x+y_offset);
            drawPoint(-y+x_offset, -x+y_offset);

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }
        glEnd();
        glFlush();
    }
}
