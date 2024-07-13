#include <iostream>
#include "bloom_filter.h"

int main() {
    BloomFilter bloomFilter;

    // Leer datos desde un archivo CSV e insertarlos en el filtro
    std::string filename = "data.csv";
    readDataFromCSV(filename, bloomFilter);

    return 0;
}