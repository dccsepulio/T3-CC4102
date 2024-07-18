#include "word_search.cpp"
#include "bloom_filter.cpp"
#include <chrono>
#include <vector>

// Función que toma un filtro de Bloom ya creado y un archivo CSV para realizar la búsqueda
void processCSVWithBloomFilter(const std::string &filename, const std::string &csvToCheck, BloomFilter &bloomFilter, int &foundCount, int &notFoundCount) {
    std::ifstream file(csvToCheck);
    if (!file.is_open()) {
        throw std::runtime_error("No se puede abrir el archivo CSV para verificar");
    }

    std::string line;
    foundCount = 0;
    notFoundCount = 0;

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
    std::ofstream results("execution_times.csv");
    results << "data, time, palabras encontradas, palabras no encontradas\n";
    // Leer datos desde un archivo CSV e insertarlos en el filtro
    std::string filename = "data/Popular-Baby-Names-Final.csv";
    //std::string filename = "Film-Names.csv";
    readDataFromCSV(filename, bloomFilter);

    std::vector<std::string> data = {"data/1024-0.csv", "data/1024-1-4.csv", "data/1024-1-2.csv", "data/1024-3-4.csv", 
                                    "data/1024-1.csv", "data/4096-0.csv", "data/4096-1-4.csv", "data/4096-1-2.csv", 
                                    "data/4096-3-4.csv",  "data/4096-1.csv", "data/16384-0.csv", "data/16384-1-4.csv", 
                                    "data/16384-1-2.csv", "data/16384-3-4.csv", "data/16384-1.csv", "data/65536-0.csv", 
                                    "data/65536-1-4.csv", "data/65536-1-2.csv", "data/65536-3-4.csv", "data/65536-1.csv"};
    // Archivo CSV que se va a verificar
    for (std::string data : data){
        int foundCount = 0;
        int notFoundCount = 0;

        auto start = std::chrono::high_resolution_clock::now();
        processCSVWithBloomFilter(filename, data, bloomFilter, foundCount, notFoundCount);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        double time = duration.count();
        results << data << " " << time << " " << foundCount << " " << notFoundCount << "\n";
        std::cout << "execution time data = " << data << " is " << time << " seconds." << std::endl;
    }
    results.close();
    return 0;
}