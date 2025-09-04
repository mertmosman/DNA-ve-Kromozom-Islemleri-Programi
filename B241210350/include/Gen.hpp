/**       
* @ Gen.hpp  
* @ Düğümler aracılığıyla gen tutmak. Metot tanımları.
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP
class Gen {
public:
    char data; // Genin icindeki veri
    Gen* next; // Sonraki gene isaretci

    Gen(char data); // Constructor
};
#endif