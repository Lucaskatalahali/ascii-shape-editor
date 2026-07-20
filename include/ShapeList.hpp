/**
* @file         ShapeList.hpp
* @description  Şekil nesnelerini tutan tek yönlü bağlı liste yapısı.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "ShapeNode.hpp"
#include "Screen.hpp"

class ShapeList {
private:
    ShapeNode* head;

public:
    ShapeList();
    ~ShapeList();

    void addShape(Shape* s); // Ordered insertion by Z value (the shape with higher z overlaps the others)
    void drawAll(ScreenClass& screen);
    void remove(ShapeNode* nodeToRemove);
    
    ShapeNode* getHead();
    int getCount();
};

#endif