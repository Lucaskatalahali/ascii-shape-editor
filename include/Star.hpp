/**
* @file         Star.hpp
* @description  Shape sınıfından türetilen Yıldız sınıfı.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef STAR_H
#define STAR_H
#include "Shape.hpp"

class Star : public Shape {
public:
    Star(); //Generates random value 
    void Draw(ScreenClass& screen) override;
    bool canPlace(int novoX, int novoY) const override;
    char getType() override { return 'S'; }
};

#endif