/**
* @file         MainList.hpp
* @description  Ana düğümleri tutan iki yönlü bağlı liste yapısı. Dosya okuma ve yazma işlemlerini yönetir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#ifndef MAINLIST_H
#define MAINLIST_H
#include "MainNode.hpp"
#include <string>
using namespace std;

class MainList {
private:
    MainNode* head;
    MainNode* tail;

public:
    MainList();
    ~MainList();

    void append();// Add a new node (MainNode) to the end of the doubly linked list.
    MainNode* getHead();
    void remove(MainNode* node);


    void saveToFile(string filename);
    bool loadFromFile(string filename); 

};

#endif