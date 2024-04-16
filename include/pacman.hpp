#include "commons.hpp"

namespace Game{
    
    class Pacman: public BoxObject{
        public:
            int color[3];
            Pacman(int screen_height, int screen_width);
            void movePacman();
            void setDirection(Direction dirn);
            void drawPacman();
    };
}
