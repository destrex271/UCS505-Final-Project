namespace Game{
    enum Boundary{
        LSIDE, 
        RSIDE,
        BOTTOM, 
        TOP,
        NONE
    };
    class BoxObject{
        public:
            int pos_x, pos_y;
            int area_x, area_y; // Will be a square
            int screen_width, screen_height;
            
            bool isIntersecting(BoxObject const& box2);

            Boundary hitBoundary();
    };
}
