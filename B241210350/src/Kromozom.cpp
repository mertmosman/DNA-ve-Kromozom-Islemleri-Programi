/**       
* @ Kromozom.cpp  
* @ Düğümler aracılığıyla kromozom tutmak.
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#include "Kromozom.hpp"

Kromozom::Kromozom() : head(nullptr), next(nullptr) {}

Kromozom::~Kromozom() {
    Gen* current = head;
    while (current != nullptr) {
        Gen* silinecek = current;
        current = current->next;
        delete silinecek;
    }
}

void Kromozom::addGen(char data) {
    Gen* yeniGen = new Gen(data);
    if (!head) {
        head = yeniGen;
    } else {
        Gen* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = yeniGen;
    }
}