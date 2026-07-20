/**
* @file         Shape.cpp
* @description  Tüm şekiller için ortak özellikleri (x, y, z) ve sanal metotları tanımlayan soyut temel sınıf.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "Shape.hpp"
#include "Screen.hpp"

Shape::Shape() {
    x = 0; y = 0; width = 0; height = 0; z = 0;
    drawChar = ' ';
}
void Shape::move(int dx, int dy) {
    int novoX = x + dx;
    int novoY = y + dy;

    // Use virtual canPlace to decide if it's valid
    if (!canPlace(novoX, novoY)) return;
    x = novoX;
    y = novoY;
}

// Default implementation: (x,y) is the top-left corner, total width = width
bool Shape::canPlace(int novoX, int novoY) const {
    if (novoX < 0) return false;
    if (novoY < 0) return false;
    if (novoX + width > cols) return false;   // must fit entirely
    if (novoY + height > rows) return false;
    return true;
}

void Shape::setValues(int x, int y, int w, int h, int z, char c) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
    this->z = z;
    this->drawChar = c;
}