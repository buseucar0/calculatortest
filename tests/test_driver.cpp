#include <iostream>
#include "../include/operations.h"

int main() {
    int exit_status = 0; // Başlangıçta her şey yolunda kabul ediyoruz (0)

    std::cout << "=== DRIVER TESTLERI BASLIYOR ===" << std::endl;

    // TEST 1: 3 + 5 = 8 (Geçecek)
    double sonuc1 = topla(3, 5);
    if (sonuc1 == 8) {
        std::cout << "[PASS] 3 + 5 = 8" << std::endl;
    } else {
        std::cout << "[FAIL] 3 + 5 isleminde beklenen 8, gelen: " << sonuc1 << std::endl;
        exit_status = 1; // Hata bulduk, çıkış kodunu 1 yapıyoruz
    }

    // TEST 2: 5 + 5 = 25 (Bilinçli olarak patlayacak)
    double sonuc2 = topla(5, 5);
    if (sonuc2 == 25) {
        std::cout << "[PASS] 5 + 5 = 25" << std::endl;
    } else {
        std::cout << "[FAIL] 5 + 5 isleminde beklenen 25, gelen: " << sonuc2 << std::endl;
        std::cout << ">>> Jenkins bu hatayi yakalayip kirmizi yanacak! <<<" << std::endl;
        exit_status = 1; // Hata bulduk, çıkış kodunu 1 yapıyoruz
    }

    std::cout << "=== DRIVER TESTLERI BITTI ===" << std::endl;
    
    // Eğer testlerden biri bile patladıysa exit_status 1 döner ve Jenkins fail verir.
    return exit_status; 
}