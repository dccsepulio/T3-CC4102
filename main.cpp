#include "word_search.cpp"
#include "bloom_filter.cpp"

// Función que toma un filtro de Bloom ya creado y un archivo CSV para realizar la búsqueda
void processCSVWithBloomFilter(const std::string &filename, const std::string &csvToCheck, BloomFilter &bloomFilter) {
    std::ifstream file(csvToCheck);
    if (!file.is_open()) {
        throw std::runtime_error("No se puede abrir el archivo CSV para verificar");
    }

    std::string line;
    int foundCount = 0;
    int notFoundCount = 0;

    // Leer el archivo CSV a verificar
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            // Limpiar el valor
            value.erase(std::remove(value.begin(), value.end(), '\n'), value.cend());
            value.erase(std::remove(value.begin(), value.end(), '\r'), value.cend());

            // Verificar si la palabra está en el Bloom Filter
            if (bloomFilter.contains(value)) {
                // Buscar la palabra en el archivo original
                searchWordInCSV(filename, value, foundCount, notFoundCount);
            }
        }
    }

    file.close();

    // Mostrar los resultados
    std::cout << "Palabras encontradas: " << foundCount << std::endl;
    std::cout << "Palabras no encontradas: " << notFoundCount << std::endl;
}


int main() {
    BloomFilter bloomFilter;

    // Leer datos desde un archivo CSV e insertarlos en el filtro
    std::string filename = "data/Popular-Baby-Names-Final.csv";
    //std::string filename = "Film-Names.csv";
    readDataFromCSV(filename, bloomFilter);
    //std::cout << "ENTER THE ANIME: " << (bloomFilter.contains("ENTER THE ANIME") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    //std::cout << "HEIDY: " << (bloomFilter.contains("HEIDY") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    //std::cout << "GIA: " << (bloomFilter.contains("GIA") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    //std::cout << "GISELLE: " << (bloomFilter.contains("GISELLE") ? "Posiblemente en el conjunto" : "No está en el conjunto") << std::endl;
    std::string csvToCheck = "test.csv"; // Archivo CSV que se va a verificar
    processCSVWithBloomFilter(filename, csvToCheck, bloomFilter);

    return 0;
}