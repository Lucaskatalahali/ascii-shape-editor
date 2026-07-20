/**
* @file         Triangle.cpp
* @description  Shape sınıfından türetilen Üçgen sınıfı. Kendine özgü çizim ve sınır kontrolü mantığını içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "Triangle.hpp"
#include <cstdlib>

Triangle::Triangle() : Shape() {
    z = rand() % 100;
    const char opcoes[] = "+*o@#-~"; // The shapes will use these characters
    drawChar = opcoes[rand() % 7];

    bool valid = false;
    while (!valid) {
        x = rand() % cols;
        y = rand() % rows;
        height = 2 + rand() % 8; // Triangle will have height in the range 2 - 9
        width = (height * 2) - 1; // Triangle base depends on the height value to form an equilateral triangle

        // Checks if it fits on the screen (use the same logic that canPlace will use)
        int half = width / 2;
        if (y + height <= rows && x - half >= 0 && x + half < cols) {
            valid = true;
        }
    }
}
void Triangle::Draw(ScreenClass& s) {
    for (int i = 0; i < height; i++) {
        for (int j = -i; j <= i; j++) {
            int px = x + j;
            int py = y + i;
            if (px >= 0 && px < cols && py >= 0 && py < rows) {
                s.screen[py][px] = drawChar;
            }
        }
    }
}
// Overrides canPlace to treat x as the horizontal center
bool Triangle::canPlace(int novoX, int novoY) const {
    int half = width / 2;
    if (novoY < 0) return false;
    if (novoY + height > rows) return false;
    if (novoX - half < 0) return false;
    if (novoX + half >= cols) return false;
    return true;
}
