#include "include/shapes.hpp"
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
        glBegin(GL_POINTS);
        for(auto point: points){
            glVertex2f(point.first, point.second);
        }
        glEnd();
        glFlush();
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
        glClear(GL_COLOR_BUFFER_BIT);
        int y = radius, x = 0, pi = (5/4.0) - y;
        std::vector<std::pair<int, int>> points;
        while(x <= y){
            // Draw points
            glColor3f(1.0f, 1.0f, 1.0f);
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
                    points.push_back({-x + x_offset, y + y_offset});
                    points.push_back({-x + x_offset, -y + y_offset});
                    /* points.push_back({y + x_offset, x + y_offset}); */
                    /* points.push_back({y + x_offset, -x + y_offset}); */
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    break;
                }
                case 2:{
                    points.push_back({x + x_offset, y + y_offset});
                    /* points.push_back({x + x_offset, -y + y_offset}); */
                    points.push_back({-x + x_offset, y + y_offset});
                    /* points.push_back({-x + x_offset, -y + y_offset}); */
                    points.push_back({y + x_offset, x + y_offset});
                    points.push_back({y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    break;
                }
                case 3:{
                    /* points.push_back({x + x_offset, y + y_offset}); */
                    points.push_back({x + x_offset, -y + y_offset});
                    /* points.push_back({-x + x_offset, y + y_offset}); */
                    points.push_back({-x + x_offset, -y + y_offset});
                    points.push_back({y + x_offset, x + y_offset});
                    points.push_back({y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, -x + y_offset});
                    points.push_back({-y + x_offset, x + y_offset});
                    break;
                }
            }
            /* points.push_back({x + x_offset, y + y_offset}); */
            /* points.push_back({x + x_offset, -y + y_offset}); */
            /* points.push_back({-x + x_offset, y + y_offset}); */
            /* points.push_back({-x + x_offset, -y + y_offset}); */
            /* points.push_back({y + x_offset, x + y_offset}); */
            /* points.push_back({y + x_offset, -x + y_offset}); */
            /* points.push_back({-y + x_offset, x + y_offset}); */
            /* points.push_back({-y + x_offset, -x + y_offset}); */

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }

        drawPoints(points);

        glBegin(GL_LINES);
        switch(dirn){
            case 0:{
                std::cout << "LINE!" << std::endl;
                glVertex2f(y+x_offset, x+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(y+x_offset, -x+y_offset);
                glVertex2f(x_offset, y_offset);
                break;
            }
            case 1:{
                glVertex2f(-y+x_offset, x+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-y+x_offset, -x+y_offset);
                glVertex2f(x_offset, y_offset);
                break;
            }
            case 2:{
                glVertex2f(x+x_offset, -y+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-x+x_offset, -y+y_offset);
                glVertex2f(x_offset, y_offset);
                break;
            }
            case 3:{
                glVertex2f(x+x_offset, y+y_offset);
                glVertex2f(x_offset, y_offset);
                glVertex2f(-x+x_offset, y+y_offset);
                glVertex2f(x_offset, y_offset);
                break;
            }
        }

        glEnd();
        glFlush();
        /* auto pts = Line::getLinePointsDDA(-y + x_offset, x_offset, x + y_offset, y_offset); */
        /* auto pt2 = Line::getLinePointsDDA(-y + x_offset, x_offset, -x + y_offset, y_offset); */
        /*  */
        /* for(auto pt: pt1){ */
        /*     points.emplace_back(pt); */
        /* } */
        /* for(auto pt: pt2){ */
        /*     points.push_back(pt); */
        /* } */
        /* sort(points.begin(), points.end()); */
    }

    void Sprites::drawGhost(int radius, int h, int k, float r, float g, float b){
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        glColor3f(r, g, b);

        int y = radius, x = 0, pi = (5/4.0) - y;
        while(x <= y){
            drawPoint(x, y);
            drawPoint(-x, y);
            drawPoint(y, x);
            drawPoint(-y, x);

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }

        Line::drawLineVertical(-radius, 0, -radius, r, g, b);
        Line::drawLineHorizontal(-radius, radius, -radius, r, g, b);
        Line::drawLineVertical(radius, 0, -radius, r, g, b);
        
        glFlush();
    }
}
