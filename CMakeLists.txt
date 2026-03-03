cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

set(CMAKE_CXX_STANDARD 14)

# Include klasörünü tanıtıyoruz
include_directories(include)

# Kütüphane dosyalarımızı (logic) ekliyoruz
add_library(calc_logic 
    src/addition.cpp 
    src/subtraction.cpp 
    src/multiplication.cpp 
    src/division.cpp
)

# Ana uygulamayı (executable) oluşturuyoruz
add_executable(calculator src/main.cpp)
target_link_libraries(calculator calc_logic)

# Test Driver uygulamasını oluşturuyoruz
add_executable(test_driver tests/test_driver.cpp)
target_link_libraries(test_driver calc_logic)