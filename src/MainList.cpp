/**
* @file         MainList.cpp
* @description  Ana düğümleri tutan iki yönlü bağlı liste yapısı. Dosya okuma ve yazma işlemlerini yönetir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "MainList.hpp"
#include <fstream>
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Star.hpp"
#include <string>
using namespace std;

MainList::MainList() {
    head = nullptr;
    tail = nullptr;
}
MainList::~MainList() {
    MainNode* current = head;
    while (current) {
        MainNode* next = current->next;
        delete current;
        current = next;
    }
}
void MainList::append() {
    MainNode* newNode = new MainNode();
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void MainList::remove(MainNode* node) {
    if (!node) return;

    // In case it is the 1st in the list (head)
    if (node == head) {
        head = node->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // AThe list is empty now
    }
    // If it is the last in the list (tail)
    else if (node == tail) {
        tail = node->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
    }
    // If it is in the middle
    else {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
    }

    delete node;
}
bool MainList::loadFromFile(string filename) {
    ifstream file(filename);
    
    // If it fails, just return false. The main function handles the rest.
    if (!file.is_open()) {
        return false; 
    }

   // If it opened, clear the current list
    while (head) remove(head);

    string line;
    MainNode* currentNode = nullptr;

    while (file >> line) {
        if (line == "NODE") {
            append(); 
            currentNode = tail; 
            // Clears the random garbage from the constructor because we want to load from file
            while(currentNode->shapes->getHead()) {
                currentNode->shapes->remove(currentNode->shapes->getHead());
            }
        }
        else {
            // Logic for reading shapes (T, R, S) from the file (Triangle, Rectangle, Star)
            char type = line[0];
            int x, y, w, h, z;
            char c;
            file >> x >> y >> w >> h >> z >> c;
            
            Shape* newShape = nullptr;
            if (type == 'S') newShape = new Star();
            else if (type == 'R') newShape = new Rectangle();
            else if (type == 'T') newShape = new Triangle();
            
            if (newShape && currentNode) {
                newShape->setValues(x, y, w, h, z, c);
                currentNode->shapes->addShape(newShape);
            }
        }
    }
    file.close();
    return true; // Success!
}

void MainList::saveToFile(string filename) {
    ofstream file(filename);
    
    if (!file.is_open()) {
        return;
    }

    MainNode* current = head;
    while (current != nullptr) {
        file << "NODE" << endl; // Node marker, because the program needs to know where a Main Node ends and the next one begins
        
        if (current->shapes) {
            ShapeNode* sNode = current->shapes->getHead();
            while (sNode != nullptr) {
                Shape* s = sNode->data;
                // Save: TYPE X Y W H Z CHAR
                file << s->getType() << " " 
                     << s->getX() << " " 
                     << s->getY() << " " 
                     << s->getWidth() << " " 
                     << s->getHeight() << " " 
                     << s->getZ() << " " 
                     << s->getDrawChar() << endl;
                
                sNode = sNode->next;
            }
        }
        current = current->next;
    }
    file.close(); 
}
MainNode* MainList::getHead() {
    return head;
}