/**
* @file         main.cpp
* @description  Ana program döngüsü, kullanıcı arayüzü çizimi ve menü işlemlerini yöneten giriş dosyası.
* @course       Veri Yapıları 1. Öğretim A
* @assignment   1. Ödev
* @date         22/11/2025
* @author       Lucas Isaac Cassoma Katalahali
*/

#include <iostream>
#include <string>
#include <conio.h> // used for console input/output functions like getch()
#include <iomanip> // used for formatted output (setw, setprecision, etc.)
#include <cstdlib> // Used to generate random numbers and system commands (system)
#include <ctime>
#include "Screen.hpp"
#include "MainList.hpp"
#include "ShapeList.hpp"
#include <fstream>

using namespace std;

enum GameMode {
    MODE_MAIN_MENU, // Navigate between main nodes (W/S)
    MODE_SHAPE_EDIT // Move the selected shape (W/A/S/D)
};

int countMainNodes(MainList& ml) {
    int c = 0;
    MainNode* it = ml.getHead();
    while (it) { c++; it = it->next; }
    return c;
}

int indexOfNode(MainList& ml, MainNode* node) {
    int i = 0;
    MainNode* it = ml.getHead();
    while (it) {
        if (it == node) return i;
        it = it->next;
        i++;
    }
    return -1; //Not found
}

int main() {
    srand((time(NULL)));

    ScreenClass tela;
    MainList listaPrincipal;
    
    string input;
    char option;
    bool loadSuccessful = false;
    do{
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "Not: Programin icindeyken, programi sonlandirmak icin \"ESC\" tusuna basmalisin\n" << endl;
        cout << "1 - Rastgele dugumler olustur" << endl;
        cout << "2 - Dosyadan yukle" << endl;
        cout << "Secenek girin: ";
        cin >> input;
        if(input.length() > 1) option = 'x'; //Invalid input
        else option = input[0];

    // if the user chooses to load from file (data.txt)
    if (option == '2') {
        if (listaPrincipal.loadFromFile("data.txt")) {
            loadSuccessful = true;
        } else {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            cout << "Dosya bulunamadi... Rastgele dugumler olusturmak icin 1. secenegi secebilirsin" << endl;
            cout << "(Devam etmek icin bir tusa basin...)";
            _getch();
        }
    }
    }while(option != '1' && !loadSuccessful);

    // If not loaded (either because 1 was chosen or the file failed then 1 was chosen)  
    if (!loadSuccessful) {
        for (int i = 0; i < 20; i++) {
            listaPrincipal.append();
        }
    }

    GameMode mode = MODE_MAIN_MENU;
    MainNode* currentMainNode = listaPrincipal.getHead();
    ShapeNode* currentShapeNode = nullptr;

    int mainIndex = 0;
    bool running = true;

    while (running) {
    tela.clearScreen();

    
    if (currentMainNode != nullptr && currentMainNode->shapes != nullptr) {
        currentMainNode->shapes->drawAll(tela);
    }

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

        // Draw left menu + right screen
        if (currentMainNode == nullptr) {
            mainIndex = 0;
        } else {
            int idx = indexOfNode(listaPrincipal, currentMainNode);
            if (idx >= 0) mainIndex = idx;
        }

        int totalNodes = countMainNodes(listaPrincipal);
        if (totalNodes == 0) {
            // If there are no nodes, show message and wait for ESC to exit
            cout << "Kalan dugum yok. Cikmak icin ESC'ye basin..." << endl;
            char k = _getch();
            if (k == 27) break;
            else continue;
        }

        if (mainIndex >= totalNodes) mainIndex = totalNodes - 1;
        if (mainIndex < 0) mainIndex = 0;

        // Page with blocks of 6 nodes
        int pageStart = (mainIndex / 6) * 6;
        if (pageStart < 0) pageStart = 0;
        if (pageStart >= totalNodes) pageStart = max(0, totalNodes - (totalNodes % 6 == 0 ? 6 : totalNodes % 6));

        // Locate the starting node of the page
        MainNode* tempNode = listaPrincipal.getHead();
        for (int i = 0; i < pageStart && tempNode != nullptr; i++) tempNode = tempNode->next;

        int nodeCounter = 0;

        // 25 lines of the screen
        for (int row = 0; row < 25; row++) {
            
            // Left menu (fixed width: 20 characters)
            if (nodeCounter < 6 && tempNode != nullptr) {
                bool isSelected = (tempNode == currentMainNode);
                
                string suffix = (isSelected) ? " <--     " : string(9, ' ');

                // Top of the box
                if (row % 4 == 0) { 
                    // "***********" (11) + Seta (9) = 20 chars
                    cout << "***********" << suffix; 
                }
                // Middle of the box
                else if (row % 4 == 1) { 
                    int qtd = tempNode->shapes ? tempNode->shapes->getCount() : 0;
                    // "* " + num(2) + "      *" (11) + Seta (9) = 20 chars
                    cout << "* " << setw(2) << qtd << "      *" << suffix; 
                }
                // Bottom of the box
                else if (row % 4 == 2) { 
                    // "***********" (11) + Seta (9) = 20 chars
                    cout << "***********" << suffix;
                }
                // Space between nodes
                else { 
                    cout << string(20, ' '); 
                    tempNode = tempNode->next;
                    nodeCounter++;
                }
            } 
            else {
                cout << string(20, ' '); 
            }

            // Right screen
            for (int col = 0; col < cols; col++) {
                cout << tela.screen[row][col];
            }
            cout << endl; 
        }
        // Menu
        if (mode == MODE_MAIN_MENU) {
            cout << " (w/s) Hareket (f) Listeyi sec (c) Sil (Esc) Cikis: "; 
        } else { 
            cout << " (a/w/s/d) Hareket (q) Onceki sekil (e) Sonraki sekil (c) Sekil sil (g) Listeye don (Esc) Cikis: ";
        }

        char key = _getch();
        if (key >= 'A' && key <= 'Z') key += 32;

       // Here I will use the logic of the modes
        if (mode == MODE_MAIN_MENU) {
            // Navigate previous / next
            if (key == 'w' && currentMainNode && currentMainNode->prev) {
                currentMainNode = currentMainNode->prev;
                mainIndex = max(0, mainIndex - 1);
            }
            else if (key == 's' && currentMainNode && currentMainNode->next) {
                currentMainNode = currentMainNode->next;
                mainIndex++;
            }

            // Enter shape editing
            else if (key == 'f' && currentMainNode) {
                currentShapeNode = currentMainNode->shapes->getHead();
                if (currentShapeNode) mode = MODE_SHAPE_EDIT;
            }

            // DELETE MAIN NODE
            else if (key == 'c' && currentMainNode) {
                MainNode* toDelete = currentMainNode;

                // Decide the new currentMainNode before deleting
                if (toDelete->next) {
                    currentMainNode = toDelete->next;
                    // mainIndex remains pointing roughly to the same slot
                } else if (toDelete->prev) {
                    currentMainNode = toDelete->prev;
                    mainIndex = max(0, mainIndex - 1);
                } else {
                    // It was the only one
                    currentMainNode = nullptr;
                    mainIndex = 0;
                }

                listaPrincipal.remove(toDelete);

                // Adjust pageStart/mainIndex to not go out of bounds
                int newTotal = countMainNodes(listaPrincipal);
                if (newTotal == 0) {
                    // List became empty — exit the main drawing loop
                } else {
                    if (mainIndex >= newTotal) mainIndex = newTotal - 1;
                }
            }
        }
        // Shape editing
        else if (mode == MODE_SHAPE_EDIT) {
            if (!currentMainNode) { mode = MODE_MAIN_MENU; continue; }

            if (key == 'g') { mode = MODE_MAIN_MENU; currentShapeNode = nullptr; }

            else if (key == 'e' && currentShapeNode && currentShapeNode->next) {
                currentShapeNode = currentShapeNode->next;
            }
            else if (key == 'q') {
                ShapeNode* head = currentMainNode->shapes->getHead();
                if (currentShapeNode != head) {
                    ShapeNode* scan = head;
                    while (scan && scan->next != currentShapeNode) scan = scan->next;
                    if (scan) currentShapeNode = scan;
                }
            }

            else if (currentShapeNode) {
                if (key == 'w') currentShapeNode->data->move(0, -1);
                else if (key == 's') currentShapeNode->data->move(0, 1);
                else if (key == 'a') currentShapeNode->data->move(-1, 0);
                else if (key == 'd') currentShapeNode->data->move(1, 0);

                else if (key == 'c') {
                    // Delete current shape
                    ShapeNode* toDelete = currentShapeNode;
                    ShapeNode* nextSel = toDelete->next;

                    // If there is no next and it's not the head, choose the previous one
                    if (!nextSel && toDelete != currentMainNode->shapes->getHead()) {
                        ShapeNode* scan = currentMainNode->shapes->getHead();
                        while (scan->next != toDelete) scan = scan->next;
                        nextSel = scan;
                    }

                    currentMainNode->shapes->remove(toDelete);
                    currentShapeNode = nextSel;

                    // If the shape list became empty -> remove main node and return to main menu
                    if (!currentMainNode->shapes->getHead()) {
                        MainNode* nodeToDelete = currentMainNode;

                        if (nodeToDelete->next) {
                            currentMainNode = nodeToDelete->next;
                        } else if (nodeToDelete->prev) {
                            currentMainNode = nodeToDelete->prev;
                            mainIndex = max(0, mainIndex - 1);
                        } else {
                            currentMainNode = nullptr;
                            mainIndex = 0;
                        }

                        listaPrincipal.remove(nodeToDelete);

                        mode = MODE_MAIN_MENU;
                        currentShapeNode = nullptr;
                    }
                }
            }
        }
        // If the user presses ESC (27 in ASCII), the program ends
        if (key == 27) running = false;
    }

    listaPrincipal.saveToFile("data.txt");

    return 0;
}
