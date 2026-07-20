/**
* @file         ShapeNode.cpp
* @description  Şekiller listesi için düğüm yapısı. Bir şekil nesnesine (Shape*) işaretçi tutar.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "ShapeNode.hpp"

ShapeNode::ShapeNode(Shape* s) {
    data = s;
    next = nullptr;
}

ShapeNode::~ShapeNode() {} // Empty: The memory for 'data' will be released by the destructor/methods of ShapeList.