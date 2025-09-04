/**       
* @ DNA.cpp  
* @ Kromozomları DNA'da toplamak ve üzerinde işlemler yapmak. 
* @ 1. Öğretim B grubu
* @ 1.Ödev  
* @ 26.11.2024 
* @ MUHAMMED OSMAN MERT muhammed.mert1@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include "DNA.hpp"

DNA::DNA() : head(nullptr) {}

DNA::~DNA() {
    Kromozom* current = head;
    while (current != nullptr) {
        Kromozom* sil = current;
        current = current->next;
        delete sil;
    }
}

void DNA::kromozomEkle(Kromozom* kromozom) {
    if (!head) {
        head = kromozom; // DNA bossa, ilk kromozom eklenir
    } else {
        Kromozom* temp = head;
        while (temp->next != nullptr) { // Listenin sonuna kadar ilerle
            temp = temp->next;
        }
        temp->next = kromozom; // Yeni kromozomu ekle
    }
}

void DNA::DNAYazdir() {
    Kromozom* temp = head;
    std::string output; // Yazdiracagimiz tum cıktıyı burada biriktirecegiz

    while (temp != nullptr) {
        Gen* current = temp->head;

        while (current != nullptr) {
            output += current->data; // Geni ekle
            output += " ";           // Bosluk ekle
            current = current->next;
        }

        output += "\n"; // Kromozomlar arasında yeni satır ekle
        temp = temp->next;
    }

    std::cout << output; // Tamponu bir seferde ekrana yazdır
    // Bu sayede BAGLI LISTEDEN aldigimiz verileri yazdirmis olduk.
}

void DNA::dosyadanOku(const std::string& dnatxt) {
    std::ifstream file(dnatxt);
    if (!file.is_open()) {
        std::cerr << "Dosya acilamadi: " << dnatxt << std::endl;
        return;
    }

    std::string line;
    char ch;

    while (file.get(ch)) {  // Karakter karakter okuma
        if (ch == '\n') {  // Satir sonu
            if (!line.empty()) {
                Kromozom* kromozom = new Kromozom();
                for (char& c : line) {
                    if (c != ' ') {  // Boslukları yok say
                        kromozom->addGen(c);  // Gen olarak ekle
                    }
                }
                this->kromozomEkle(kromozom);  // Kromozomu DNA'ya ekle
            }
            line.clear();  // Yeni satır icin temizle
        } else {
            line += ch;  // Satirdaki karakteri birlestir
        }
    }

    // Son satırı da isleyelim
    if (!line.empty()) {
        Kromozom* kromozom = new Kromozom();
        for (char& c : line) {
            if (c != ' ') {
                kromozom->addGen(c);
            }
        }
        this->kromozomEkle(kromozom);
    }

    file.close();
}


// Kullanicidan iki kromozomun satir numarasini alip caprazlama yapar
void DNA::caprazla(int index1, int index2) {
    Kromozom* kromozom1 = getKromozom(index1);
    Kromozom* kromozom2 = getKromozom(index2);

    if (!kromozom1 || !kromozom2) {
        std::cerr << "Gecersiz kromozom index(ler)i!" << std::endl;
        return;
    }

    // Ilk kromozomun ortasina kadar olan kismi al
    Gen* mid1_sol = nullptr;
    Gen* mid1_sag = nullptr;
    kromozomAyir(kromozom1, mid1_sol, mid1_sag);

    // Ikinci kromozomun ortasina kadar olan kismi al
    Gen* mid2_sol = nullptr;
    Gen* mid2_sag = nullptr;
    kromozomAyir(kromozom2, mid2_sol, mid2_sag);

    // Yeni kromozomları olustur
    Kromozom* yeniKromozom1 = new Kromozom();
    kromozomaGenEkle(yeniKromozom1, mid1_sol);
    kromozomaGenEkle(yeniKromozom1, mid2_sag);

    Kromozom* yeniKromozom2 = new Kromozom();
    kromozomaGenEkle(yeniKromozom2, mid1_sag);
    kromozomaGenEkle(yeniKromozom2, mid2_sol);

    // Yeni kromozomlari populasyona ekle
    this->kromozomEkle(yeniKromozom1);
    this->kromozomEkle(yeniKromozom2);
    std::cout<<"Caprazlama islemi basariyla tamamlandi! "<<std::endl;
}

// Bir kromozomu ikiye boler, ortayi hesaplar
void DNA::kromozomAyir(Kromozom* kromozom, Gen*& sol, Gen*& sag) {
    int genSayaci = 0;
    Gen* current = kromozom->head;

    // Gen sayisıni hesapla
    while (current) {
        genSayaci++;
        current = current->next;
    }

    int mid = genSayaci / 2; // Ortadaki gen
    current = kromozom->head;

    // Sol ve sag taraflari ayir
    int index = 0;
    while (current) {
        Gen* yeniGen = new Gen(current->data);
        if (index < mid) {
            if (!sol) {
                sol = yeniGen;
            } else {
                listeyeGenEkle(sol, yeniGen);
            }
        } else if (genSayaci % 2 == 0 || index > mid) { // Tek eleman varsa ortada olan elemani atla
            if (!sag) {
                sag = yeniGen;
            } else {
                listeyeGenEkle(sag, yeniGen);
            }
        }
        current = current->next;
        index++;
    }
}

// Genleri bir kromozoma ekler
void DNA::listeyeGenEkle(Gen*& head, Gen* yeniGen) {
    if (!head) {
        head = yeniGen;
    } else {
        Gen* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = yeniGen;
    }
}

// Bagli listeyi bir kromozoma ekler
void DNA::kromozomaGenEkle(Kromozom* kromozom, Gen* _gen) {
    while (_gen) {
        kromozom->addGen(_gen->data);
        _gen = _gen->next;
    }
}

Kromozom* DNA::getKromozom(int index) {
    int simdikiIndex = 0;
    Kromozom* current = head;
    while (current) {
        if (simdikiIndex == index) {
            return current;
        }
        current = current->next;
        simdikiIndex++;
    }
    return nullptr; // Gecersiz index
}

// Kullanicidan kromozom satir numarasi ve gen numarasi alarak mutasyon yapar
void DNA::mutasyon(int kromozomIndex, int genIndex) {
    Kromozom* kromozom = getKromozom(kromozomIndex);
    if (!kromozom) {
        std::cerr << "Gecersiz kromozom index'i!" << std::endl;
        return;
    }

    Gen* suanki = kromozom->head;
    int suankIndex = 0;

    // Belirtilen pozisyondaki gene git
    while (suanki && suankIndex < genIndex) {
        suanki = suanki->next;
        suankIndex++;
    }

    if (suanki) {
        suanki->data = 'X'; // Mutasyon: Genin degerini 'X' ile degistir
        std::cout << "Mutasyon islemi basariyla gerceklestirildi!" << std::endl;
    } else {
        std::cerr << "Gecersiz gen index'i!" << std::endl;
    }
}

void DNA::ozelYazdirma() {
    Kromozom* temp = head;

    while (temp != nullptr) {
        Gen* current = temp->head;
        char ilkGen = current->data;
        char sonuc = ilkGen;

        // Sagdan sola gitmek icin tum genleri tek geciste kontrol et
        while (current != nullptr) {
            if (current->data < ilkGen) {
                sonuc = current->data;
            }
            current = current->next;
        }

        std::cout << sonuc << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

// Otomatik islemleri uygular
void DNA::islemleriAl() {
    std::ifstream file("Islemler.txt");
    if (!file.is_open()) {
        std::cerr << "Islemler dosyasi acilamadi." << std::endl;
        return;
    }

    char karakter = '\0';
    int index1 = -1, index2 = -1;
    char ch;
    int simdikiYer = 0; // 0: Islem turu, 1: Ilk indeks, 2: Ikinci indeks

    while (file.get(ch)) {
        if (ch == '\n') {  // Satir sonu
            // Islem turune gore fonksiyon cagir
            if (karakter == 'C') {
                caprazla(index1, index2);
                std::cout << "Caprazlama islemi: " << index1 << " ve " << index2 << " basariyla yapildi." << std::endl;
            } else if (karakter == 'M') {
                mutasyon(index1, index2);
                std::cout << "Mutasyon islemi: " << index1 << " kromozomundaki " << index2 << " numarali gen basariyla mutasyona ugratildi." << std::endl;
            } else {
                std::cerr << "Gecersiz islem turu!" << std::endl;
            }

            // Satir bitince resetle
            karakter = '\0';
            index1 = -1;
            index2 = -1;
            simdikiYer = 0;
        } else if (ch == ' ') {
            simdikiYer++; // Boslukta durumu degistir
        } else {
            // Karakteri duruma gore isle
            if (simdikiYer == 0) {
                karakter = ch; // Islem turu
            } else if (simdikiYer == 1) {
                if (index1 == -1) index1 = 0;
                index1 = index1 * 10 + (ch - '0'); // Ilk indeks
            } else if (simdikiYer == 2) {
                if (index2 == -1) index2 = 0;
                index2 = index2 * 10 + (ch - '0'); // Ikinci indeks
            }
        }
    }

    // Son satiri isleyelim
    if (karakter != '\0') {
        if (karakter == 'C') {
            caprazla(index1, index2);
            std::cout << "Caprazlama islemi: " << index1 << " ve " << index2 << " basariyla yapildi." << std::endl;
        } else if (karakter == 'M') {
            mutasyon(index1, index2);
            std::cout << "Mutasyon islemi: " << index1 << " kromozomundaki " << index2 << " numarali gen basariyla mutasyona ugratildi." << std::endl;
        } else {
            std::cerr << "Gecersiz islem turu!" << std::endl;
        }
    }

    file.close();
}