#include <iostream>
#include <string>
#include "operations.h"

int main(int argc, char* argv[]) {
    // Argüman kontrolü: ./calculator <sayi1> <sayi2> <islem>
    if (argc < 4) {
        std::cerr << "Kullanim: ./calculator <sayi1> <sayi2> <islem>" << std::endl;
        std::cerr << "Islemler: topla, cikar, carp, bol" << std::endl;
        return 1;
    }

    // Gelen parametreleri sayiya ceviriyoruz (double kullanarak ondalikli sayilara da izin veriyoruz)
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    std::string islem = argv[3];

    if (islem == "topla") {
        std::cout << topla(a, b) << std::endl;
    } else if (islem == "cikar") {
        std::cout << cikar(a, b) << std::endl;
    } else if (islem == "carp") {
        std::cout << carp(a, b) << std::endl;
    } else if (islem == "bol") {
        std::cout << bol(a, b) << std::endl;
    } else {
        std::cerr << "Hata: Gecersiz islem!" << std::endl;
        return 1;
    }

    return 0;
}