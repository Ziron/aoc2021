#include <iostream>
#include <limits>

int main() {
    int xmin = 185;
    int xmax = 221;
    int ymin = -122;
    int ymax = -74;
    
    int hits = 0;

    for (int vy0 = ymin; vy0 <= 1000; vy0++) {
        for (int vx0 = 1; vx0 <= xmax; vx0++) {
            int x = 0;
            int y = 0;
            int vx = vx0;
            int vy = vy0;
            for (int i = 1; ; i++) {
                x += vx;
                y += vy;

                vy--;
                if (vx) vx--;
                
                if (x > xmax || y < ymin) break; // Missed

                if (vx <= 0 && x < xmin) break; // Missed

                if (xmin <= x && x <= xmax && ymin <= y && y <= ymax) {
                    // Hit
                    std::cout << "Hit with " << vx0 << ',' << vy0 << std::endl;
                    hits++;
                    break;
                }

            }
        }
    }

    std::cout << "Hits: " << hits << std::endl;
}