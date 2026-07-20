/**
* @file         Screen.hpp
* @description  Konsol ekranı için 2 boyutlu karakter dizisi (buffer) ve ekran temizleme işlemlerini yöneten sınıf.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef SCREEN_H
#define SCREEN_H

// Global Project Dimensions
const int rows = 25;
const int cols = 100;

class ScreenClass {
public:
    char screen[rows][cols];

    ScreenClass();
    void clearScreen();
};

#endif