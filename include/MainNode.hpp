/**
* @file         MainNode.hpp
* @description  Ana liste için düğüm yapısı. İçerisinde şekiller listesini barındırır.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef MAINNODE_H
#define MAINNODE_H
#include "ShapeList.hpp"

class MainNode {
public:
    MainNode* next;
    MainNode* prev;
    ShapeList* shapes;

    MainNode();
    ~MainNode();
};

#endif