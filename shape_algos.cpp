#include "include/shape_algos.hpp"

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
}
