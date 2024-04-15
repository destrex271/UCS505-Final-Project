#include <vector>

namespace Game{
    class Ghost{
        private:
            int pos_x, pos_y;
            int screen_height, screen_width;
            bool harmless;
            int timeLeftHarmless;
            int pointsIfEaten;
            float color[3];

        public:

            Ghost();
            void moveGhost(int pos_x_pacman, int pos_y_pacman);
            void renderGhost(int radius = 200, int h = 0, int k = 0, float r = 1.0, float g = 0.0, float b = 0.0);
            void setHarmless(bool state);
            void setGhostColor(float r, float g, float b);
            std::vector<float> getGhostColor();
    };
}