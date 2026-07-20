/**
* @file         Screen.cpp
* @description  Konsol ekranı için 2 boyutlu karakter dizisi (buffer) ve ekran temizleme işlemlerini yöneten sınıf.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "Screen.hpp"

ScreenClass::ScreenClass() {
    clearScreen();
}
void ScreenClass::clearScreen() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            screen[i][j] = ' '; 
        }
    }
}