/**
* @file         Star.cpp
* @description  Shape sınıfından türetilen Yıldız sınıfı. Kendine özgü çizim ve sınır kontrolü mantığını içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "Star.hpp"
#include <cstdlib>

Star::Star() : Shape() {
    z = rand() % 100;
    const char opcoes[] = "+*o@#-~"; 
    drawChar = opcoes[rand() % 7];

    bool valid = false;
    while (!valid) {
        x = rand() % cols;
        y = rand() % rows;
        height = 3 + rand() % 7; // Star will have height in the range 3 - 9
        
        if (height % 2 == 0) width = height - 1; // To maintain symmetry at the center
        else width = height;

        int half = width / 2;

        if (y + height <= rows && x - half >= 0 && x + half < cols) {
            valid = true;
        }
    }
}
void Star::Draw(ScreenClass& s) {
    int center_width_half = width / 2;
    
    // Top Triangle (upper part of the star)
    for (int i = 0; i <= center_width_half; i++) {
        for (int j = -i; j <= i; j++) {
            int px = x + j;
            int py = y + i;
            if (px >= 0 && px < cols && py >= 0 && py < rows) s.screen[py][px] = drawChar;
        }
    }
    // Bottom Triangle (lower part of the star)
    for (int i = center_width_half + 1; i < height; i++) {
        int k = height - i;
        for (int j = -(k-1); j <= (k-1); j++) {
             int px = x + j;
             int py = y + i;
             if (px >= 0 && px < cols && py >= 0 && py < rows) s.screen[py][px] = drawChar;
        }
    }
}

// canPlace for star (x = horizontal center)
bool Star::canPlace(int novoX, int novoY) const {
    int half = width / 2;
    if (novoY < 0) return false;
    if (novoY + height > rows) return false;
    if (novoX - half < 0) return false;
    if (novoX + half >= cols) return false;
    return true;
}
