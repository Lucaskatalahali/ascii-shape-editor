/**
* @file         ShapeList.cpp
* @description  Şekil nesnelerini tutan tek yönlü bağlı liste yapısı. Z değerine göre sıralı ekleme mantığını içerir.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         20/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include "ShapeList.hpp"

ShapeList::ShapeList() { head = nullptr; }

ShapeList::~ShapeList() {
    ShapeNode* current = head;
    while (current) {
        ShapeNode* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
}
void ShapeList::addShape(Shape* s) {
    ShapeNode* newNode = new ShapeNode(s);
    int newZ = s->getZ();

    if (!head || newZ < head->data->getZ()) {
        newNode->next = head;
        head = newNode;
    } else {
        ShapeNode* current = head;
        while (current->next && current->next->data->getZ() <= newZ) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void ShapeList::drawAll(ScreenClass& screen) {
    ShapeNode* current = head;
    while (current) {
        current->data->Draw(screen);
        current = current->next;
    }
}
void ShapeList::remove(ShapeNode* nodeToRemove) {
    if (!head || !nodeToRemove) return;
    
    if (head == nodeToRemove) {
        head = nodeToRemove->next;
        delete nodeToRemove->data;
        delete nodeToRemove;
        return;
    }

    ShapeNode* temp = head;
    while (temp->next && temp->next != nodeToRemove) {
        temp = temp->next;
    }

    if (temp->next == nodeToRemove) {
        temp->next = nodeToRemove->next;
        delete nodeToRemove->data;
        delete nodeToRemove;
    }
}

ShapeNode* ShapeList::getHead() { return head; }

int ShapeList::getCount() {
    int count = 0;
    ShapeNode* temp = head;
    while(temp) { count++; temp = temp->next; }
    return count;
}