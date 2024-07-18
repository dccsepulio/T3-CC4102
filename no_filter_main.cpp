#include "word_search.cpp"
#include "bloom_filter.cpp"
#include <chrono>
#include <vector>

void processCSV(const std::string &filename, const std::string &csvToCheck, int &foundCount, int &notFoundCount) {
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
            searchWordInCSV(filename, value, foundCount, notFoundCount);
        }
    }

    file.close();

    // Mostrar los resultados
    std::cout << "Palabras encontradas: " << foundCount << std::endl;
    std::cout << "Palabras no encontradas: " << notFoundCount << std::endl;
}


int main() {
    BloomFilter bloomFilter;
    std::ofstream results("execution_times_without_filter_1.csv");
    results << "data, time, palabras encontradas, palabras no encontradas\n";
    // Leer datos desde un archivo CSV e insertarlos en el filtro
    std::string filename = "data/Popular-Baby-Names-Final.csv";
    //std::string filename = "Film-Names.csv";
    readDataFromCSV(filename, bloomFilter);

    std::vector<std::string> data = {"data/65536-1-4.csv"};
    // Archivo CSV que se va a verificar
    for (std::string data : data){
        int foundCount = 0;
        int notFoundCount = 0;

        auto start = std::chrono::high_resolution_clock::now();
        processCSV(filename, data, foundCount, notFoundCount);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        double time = duration.count();
        results << data << "," << time << "," << foundCount << "," << notFoundCount << "\n";
        std::cout << "execution time data = " << data << " is " << time << " seconds." << std::endl;
    }
    results.close();
    return 0;
}