namespace Game{
    class BoxObject{
        public:
            int pos_x, pos_y;
            int area_x, area_y; // Will be a square
            
            bool isIntersecting(BoxObject const& box2){
                if(this->pos_x - this->area_x <= box2.pos_x && this->pos_x + this->area_x >= box2.pos_x){
                    if(this->pos_y - this->area_y <= box2.pos_y && this->pos_y + this->area_y >= box2.pos_y){
                        return true;
                    }
                }else if(box2.pos_x - box2.area_x <= this->pos_x && box2.pos_x + box2.area_x >= this->pos_x){
                    if(box2.pos_y - box2.area_y <= this->pos_y && box2.pos_y - box2.area_y >= this->pos_y){
                        return true;
                    }
                }
                return false;
            }
    };
}
