
namespace Game{
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class Pacman{
        private:
            int pos_x;
            int pos_y;
            int screen_height, screen_width;
            int color[3];
            Direction currentDirection;
        public:
            Pacman(int screen_height, int screen_width);
            void movePacman();
            void setDirection(Direction dirn);
            void drawPacman();
    };
}
