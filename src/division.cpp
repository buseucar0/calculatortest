#include "operations.h"
#include <iostream>

double bol(double a, double b) {
    if (b == 0) {
        std::cerr << "Hata: Sifira bolme yapilamaz!" << std::endl;
        return 0; // Basitlik adina 0 donuyoruz, gercek projelerde exception firlatilir.
    }
    return a / b;
}