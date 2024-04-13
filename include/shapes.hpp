#include <vector>
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

namespace Game{
    // Shapes
    void drawPoint(int x, int y);
    namespace Circle{
        std::vector<int> calc_d_MidPoint(int pi, int x, int y); 
        void drawPacmanCircle(int radius, int x_offset, int y_offset);
        void drawCircle(int radius, int x_offset, int y_offset);
    }

    namespace Line{
        void drawLineDDA(int x1, int x2, int y1, int y2);
    }
}
