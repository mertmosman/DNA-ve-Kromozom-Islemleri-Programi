/**       
* @ Kromozom.hpp  
* @ Düğümler aracılığıyla kromozom tutmak. Metot tanımları.
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "Gen.hpp"
#include <iostream>

class Kromozom {
public:
    Gen* head;        // Kromozomun ilk genine isaretci
    Kromozom* next;   // Sonraki kromozoma isaretci
    Kromozom();       // Constructor
    ~Kromozom();      // Destructor

    void addGen(char data); // Gene ekleme fonksiyonu
};
#endif