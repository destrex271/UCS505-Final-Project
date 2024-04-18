namespace Game{
    enum Boundary{
        LSIDE, 
        RSIDE,
        BOTTOM, 
        TOP,
        NONE
    };
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class BoxObject{
        public:
            int pos_x, pos_y;
            int area_x, area_y; // Will be a square
            int acc_x, acc_y;
            int screen_width, screen_height;
            Direction currentDirection;
            
            bool isIntersecting(BoxObject const& box2);

            Boundary hitBoundary();

            // virtual void checkCollisions() = 0;
    };
}
