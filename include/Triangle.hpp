/**
* @file         Triangle.hpp
* @description  Shape sınıfından türetilen Üçgen sınıfı.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.hpp"

class Triangle : public Shape {
public:
    Triangle(); // Generates random value  
    void Draw(ScreenClass& screen) override;
    bool canPlace(int novoX, int novoY) const override;

    
    char getType() override { return 'T'; }
};
#endif
