#include "include/shapes.hpp"
#include <GL/gl.h>
#include <algorithm>

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
        glPointSize(2.0);
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

    void Circle::drawPacmanCircle(int radius, int x_offset, int y_offset){
        glClear(GL_COLOR_BUFFER_BIT);
        int y = radius, x = 0, pi = (5/4.0) - y;
        std::vector<std::pair<int, int>> points;
        while(x <= y){
            // Draw points
            glColor3f(1.0f, 1.0f, 1.0f);
            points.push_back({x, y});
            points.push_back({x, -y});
            points.push_back({-x, y});
            points.push_back({-x, -y});
            points.push_back({y, x});
            points.push_back({y, -x});

            std::vector<int> coords = Circle::calc_d_MidPoint(pi, x, y);
            pi = coords[0];
            x = coords[1];
            y = coords[2];
        }

        auto pts = Line::getLinePointsDDA(-y, x_offset, x, y_offset);
        auto pt2 = Line::getLinePointsDDA(-y, x_offset, -x, y_offset);
        
        for(auto pt: pts){
            points.emplace_back(pt);
        }
        for(auto pt: pt2){
            points.push_back(pt);
        }

        sort(points.begin(), points.end());
        drawPoints(points);
    }
}
