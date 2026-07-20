/**
* @file         ShapeNode.hpp
* @description  Şekiller listesi için düğüm yapısı. Bir şekil nesnesine (Shape*) işaretçi tutar.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef SHAPENODE_H
#define SHAPENODE_H
#include "Shape.hpp"

class ShapeNode {
public:
    Shape* data;
    ShapeNode* next;

    ShapeNode(Shape* s);
    ~ShapeNode();
};

#endif