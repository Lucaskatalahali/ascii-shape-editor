/**
* @file         Rectangle.cpp
* @description  Shape sınıfından türetilen Dikdörtgen sınıfı. Kendine özgü çizim ve sınır kontrolü mantığını içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "Rectangle.hpp"
#include <cstdlib>

Rectangle::Rectangle() : Shape() {
    z = rand() % 100;
    const char opcoes[] = "+*o@#-~"; 
    drawChar = opcoes[rand() % 7]; 

    bool valid = false;
    while (!valid) {
        x = rand() % cols;
        y = rand() % rows;
        width = 3 + rand() % 8; //Rectabgle will have width in the range 3 - 10
        height = 2 + rand() % 8; //Rectabgle will have height in the range 2 - 9

        if (x + width <= cols && y + height <= rows) {
            valid = true;
        }
    }
}

void Rectangle::Draw(ScreenClass& s) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int px = x + j;
            int py = y + i;
            if (px >= 0 && px < cols && py >= 0 && py < rows) {
                s.screen[py][px] = drawChar;
            }
        }
    }
}