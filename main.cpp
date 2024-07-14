
#include "bloom_filter.cpp"

int main() {
    BloomFilter bloomFilter;

    // Leer datos desde un archivo CSV e insertarlos en el filtro
    std::string filename = "data/Popular-Baby-Names-Final.csv";
    //std::string filename = "Film-Names.csv";
    readDataFromCSV(filename, bloomFilter);
    std::cout << "ENTER THE ANIME: " << (bloomFilter.contains("ENTER THE ANIME") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    std::cout << "HEIDY: " << (bloomFilter.contains("HEIDY") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    std::cout << "GIA: " << (bloomFilter.contains("GIA") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    std::cout << "GISELLE: " << (bloomFilter.contains("GISELLE") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;

    return 0;
}