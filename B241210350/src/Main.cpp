/**       
* @ Main.cpp  
* @ İşlemlerin gerçekleştirilmesi ve menü fonksiyonu
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "DNA.hpp"

void menuYazdir() {
    std::cout << "---- DNA Islemleri Menu ----" << std::endl;
    std::cout << "1. DNA'yi Dosyadan Oku" << std::endl;
    std::cout << "2. Caprazlama" << std::endl;
    std::cout << "3. Mutasyon" << std::endl;
    std::cout << "4. Otomatik Islemleri Uygula" << std::endl;
    std::cout << "5. Ozel Ekrana Yaz" << std::endl;
    std::cout << "6. Ekrana Yazdir" << std::endl;
    std::cout << "7. Cikis" << std::endl;
    std::cout << "Seciminizi yapin (1-7): ";
}

int main() {
    DNA* dna = new DNA();
    int secim;
    int kromozomIndex1, kromozomIndex2, genIndex;

    do {
        menuYazdir(); // Menu yazdir
        std::cin >> secim;

        switch (secim) {
            case 1: // DNA'yi Dosyadan Oku
                dna->dosyadanOku("Dna.txt"); // Dosyadan DNA'yi oku
                std::cout << "DNA dosyasi basariyla okundu!" << std::endl;
                break;

            case 2: // Caprazlama
                std::cout << "Ilk kromozomun numarasini girin: ";
                std::cin >> kromozomIndex1;
                std::cout << "Ikinci kromozomun numarasini girin: ";
                std::cin >> kromozomIndex2;
                dna->caprazla(kromozomIndex1, kromozomIndex2); // Caprazlama islemi
                break;

            case 3: // Mutasyon
                std::cout << "Mutasyon yapacaginiz kromozom numarasini girin: ";
                std::cin >> kromozomIndex1;
                std::cout << "Mutasyon yapilacak gen numarasini girin: ";
                std::cin >> genIndex;
                dna->mutasyon(kromozomIndex1, genIndex); // Mutasyon islemi
                break;

            case 4: // Otomatik Islemleri Uygula
                dna->islemleriAl();
                break;
                
            case 5: // Ozel Ekrana Yaz
                std::cout << "Ozel ekran yazdirma islemi:" << std::endl;
                dna->ozelYazdirma();
                break;

            case 6: // Ekrana yazdır
                std::cout << "DNA'nin su anki durumu:" << std::endl;
                dna->DNAYazdir();
                break;

            case 7: // Cikis
                std::cout << "Programdan cikiliyor..." << std::endl;
                break;

            default:
                std::cout << "Gecersiz secim! Lutfen 1 ile 7 arasinda bir secenek girin." << std::endl;
        }

    } while (secim != 7); // Cikis secenegi secilene kadar menuyu gosterir
    delete dna;
    return 0;
}