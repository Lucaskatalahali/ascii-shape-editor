/**
* @file         MainNode.cpp
* @description  Ana liste için düğüm yapısı. İçerisinde şekiller listesini barındırır ve rastgele şekil üretimi yapar.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "MainNode.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"
#include <cstdlib>

MainNode::MainNode() {
    next = nullptr;
    prev = nullptr;
    shapes = new ShapeList();

    int numShapes = 2 + rand() % 6; // Generate 2 to 7 shapes
    for (int i = 0; i < numShapes; i++) {
        int type = rand() % 3;
        if (type == 0) shapes->addShape(new Star());
        else if (type == 1) shapes->addShape(new Triangle());
        else shapes->addShape(new Rectangle());
    }
}

MainNode::~MainNode() {
    delete shapes;
}