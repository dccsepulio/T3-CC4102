#include "bloom_filter.h"
#include "murmurhash3.h"
#include <fstream>
#include <sstream>
#include <string>

BloomFilter::BloomFilter() {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        seeds.push_back(i);
    }
}

void BloomFilter::insert(const std::string &element) {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        uint32_t hashValue = MurmurHash3(element.c_str(), element.size(), seeds[i]) % FILTER_SIZE;
        bitArray.set(hashValue);
    }
}

bool BloomFilter::contains(const std::string &element) const {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        uint32_t hashValue = MurmurHash3(element.c_str(), element.size(), seeds[i]) % FILTER_SIZE;
        if (!bitArray.test(hashValue)) {
            return false;
        }
    }
    return true;
}

void readDataFromCSV(const std::string &filename, BloomFilter &bloomFilter) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("No se puede abrir el archivo CSV");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {
            bloomFilter.insert(value);
        }
    }

    file.close();
}