#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>


// Función que busca una palabra en un archivo CSV de manera secuencial y cuenta las ocurrencias
void searchWordInCSV(const std::string &filename, const std::string &word, int &foundCount, int &notFoundCount) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("No se puede abrir el archivo CSV");
    }

    std::string line;
    bool wordFound = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            // Limpiar el valor
            value.erase(std::remove(value.begin(), value.end(), '\n'), value.cend());
            value.erase(std::remove(value.begin(), value.end(), '\r'), value.cend());

            if (value == word) {
                foundCount++;
                wordFound = true;
                break;
            }
        }
        if (wordFound) {
            break;
        }
    }

    if (!wordFound) {
        notFoundCount++;
    }

    file.close();
}