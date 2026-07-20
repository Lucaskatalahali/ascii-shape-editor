/**
* @file         Shape.hpp
* @description  Tüm şekiller için ortak özellikleri (x, y, z) ve sanal metotları tanımlayan soyut temel sınıf.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef SHAPE_H
#define SHAPE_H

#include "Screen.hpp"

class Shape {
protected:
    int x, y;
    int width, height;
    int z;
    char drawChar;

public:
    Shape(); 
    virtual ~Shape() {} 

    virtual void Draw(ScreenClass& screen) = 0; // Pure virtual method (Abstract)
    int getZ() const { return z; }

    // Move with validation via canPlace (override for shapes with different semantics)
    void move(int dx, int dy);

    // Subclasses (Triangle, Star) will override to treat x as the horizontal center.
    virtual bool canPlace(int novoX, int novoY) const;
    


    virtual char getType() = 0; // Retorna 'T', 'R' ou 'S'
    
    // Método para carregar dados do arquivo (sobrescreve o aleatório)
    void setValues(int x, int y, int w, int h, int z, char c);
    
    // Getters necessários para salvar
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    char getDrawChar() const { return drawChar; }
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif
