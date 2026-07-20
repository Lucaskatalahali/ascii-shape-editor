/**
* @file         Rectangle.hpp
* @description  Shape sınıfından türetilen Dikdörtgen sınıfı. Kendine özgü çizim ve sınır kontrolü mantığını içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(); //Generates random value 
    void Draw(ScreenClass& screen) override;
    char getType() override { return 'R'; }
};

#endif