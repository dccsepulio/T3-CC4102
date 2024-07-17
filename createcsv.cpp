#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <random>

// Función para leer un CSV y devolver un vector de palabras
std::vector<std::string> readCSV(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            words.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
    }
    return words;
}

// Función para escribir un vector de palabras en un CSV
void writeCSV(const std::string& filename, const std::vector<std::string>& words) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const std::string& word : words) {
            file << word << "\n";
        }
        file.close();
    } else {
        std::cerr << "No se pudo escribir en el archivo: " << filename << std::endl;
    }
}

// Función para seleccionar palabras aleatorias de un vector
std::vector<std::string> selectRandomWords(const std::vector<std::string>& words, int count) {
    std::vector<std::string> selectedWords;
    if (count > words.size()) {
        count = words.size();
    }
    std::vector<int> indices(words.size());
    std::iota(indices.begin(), indices.end(), 0);
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);
    
    for (int i = 0; i < count; ++i) {
        selectedWords.push_back(words[indices[i]]);
    }
    return selectedWords;
}

int main() {
    // Nombre del archivo de entrada y salida
    std::string inputFilename = "data/Popular-Baby-Names-Final.csv";
    //std::string inputFilename = "data/worldcities.csv";
    std::string outputFilename = "test.csv";
    
    // Número de palabras a seleccionar
    int numberOfWords = 1024;

    // Leer las palabras del archivo CSV
    std::vector<std::string> words = readCSV(inputFilename);
    
    // Seleccionar palabras aleatorias
    std::vector<std::string> randomWords = selectRandomWords(words, numberOfWords);

    // Escribir las palabras seleccionadas en un nuevo archivo CSV
    writeCSV(outputFilename, randomWords);

    std::cout << "Proceso completado. Las palabras seleccionadas se han guardado en " << outputFilename << std::endl;

    return 0;
}