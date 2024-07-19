#include <bitset>
#include <vector>
#include <string>

const int FILTER_SIZE = 1500000;  // Tamaño del arreglo M en bits
const int HASH_FUNCTIONS = 7;  // Número de funciones hash

class BloomFilter {
private:
    std::bitset<FILTER_SIZE> bitArray;  // Arreglo M de bits
    std::vector<uint32_t> seeds;  // Semillas para las funciones hash

public:
    BloomFilter();
    void insert(const std::string &element);
    bool contains(const std::string &element) const;
};

void readDataFromCSV(const std::string &filename, BloomFilter &bloomFilter);
