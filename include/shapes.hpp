#include <vector>
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

namespace Game{
    // Shapes
    void drawPoint(int x, int y);
    void drawPolygon(std::vector<std::pair<int,int>> points);
    namespace Circle{
        std::vector<int> calc_d_MidPoint(int pi, int x, int y); 
        void drawPacmanCircle(int radius, int x_offset, int y_offset, int dirn);
        void drawCircle(int radius, int x_offset, int y_offset);
        void drawSemicircle(int radius, int x_offset, int y_offset, float r = 1, float g = 0, float b = 0);

    }

    namespace Line{
        void drawLineDDA(int x1, int x2, int y1, int y2);

        std::vector<std::pair<int, int>> getLinePointsDDA(int x1, int x2, int y1, int y2);

        void drawLineHorizontal(int x1, int x2, int y, float r, float g, float b);
        void drawLineVertical(int x, int y1, int y2, float r, float g, float b);
    }

    namespace Sprites{
        void drawGhost(int radius = 200, int h = 0, int k = 0, float r = 1., float g = 0., float b = 0.);
    }
}
