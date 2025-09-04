/**       
* @ DNA.hpp  
* @ Kromozomları DNA'da toplamak ve üzerinde işlemler yapmak. Metot tanımları.
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#ifndef DNA_HPP
#define DNA_HPP
#include "Kromozom.hpp"

class DNA {
public:
    Kromozom* head; // DNA'nin ilk kromozomunu isaret eden pointer
    DNA();          // Constructor
    ~DNA();         // Destructor

    void kromozomEkle(Kromozom* kromozom); // Yeni bir kromozom ekler
    void DNAYazdir();                      // DNA'daki tum kromozomlari yazdirir
    void dosyadanOku(const std::string& dnatxt); // Dosyadan DNA'yi olusturma
    void caprazla(int index1, int index2); // Caprazlama islemi
    void kromozomAyir(Kromozom* kromozom, Gen*& sol, Gen*& sag); // Kromozomu ikiye boler
    void listeyeGenEkle(Gen*& head, Gen* yeniGen); // Bagli listeye gen ekler
    void kromozomaGenEkle(Kromozom* kromozom, Gen* _gen); // Kromozoma gen ekler
    Kromozom* getKromozom(int index); // Ilgili kromozomu dondurur
    void mutasyon(int kromozomIndex, int genIndex); // Mutasyon islemi
    void islemleriAl(); // Islemler.txt'yi okur
    
    void ozelYazdirma(); // Ozel ekrana yazdirma fonksiyonu
};
#endif