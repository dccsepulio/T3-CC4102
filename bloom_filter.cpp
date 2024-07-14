#include "bloom_filter.hpp"
#include "MurmurHash3.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

BloomFilter::BloomFilter() {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        seeds.push_back(i);
    }
}

void BloomFilter::insert(const std::string &element) {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        uint32_t hashValue;
        //std::cout << "key: "<< element.c_str() << std::endl;
        //std::cout << "len: "<< element.size() << std::endl;
        //std::cout << "seed: "<< seeds[i] << std::endl;
        MurmurHash3_x86_32(element.c_str(), element.size(), seeds[i], &hashValue);
        //std::cout << "hash: "<< hashValue << std::endl;
        hashValue %= FILTER_SIZE;
        //std::cout << "hashValue: "<< hashValue << std::endl;
        bitArray.set(hashValue);
    }
}

bool BloomFilter::contains(const std::string &element) const {
    for (int i = 0; i < HASH_FUNCTIONS; ++i) {
        uint32_t hashValue;
        //std::cout << "keyContains: "<< element.c_str() << std::endl;
        MurmurHash3_x86_32(element.c_str(), element.size(), seeds[i], &hashValue);
        hashValue %= FILTER_SIZE;
        //std::cout << "hashValueContains: "<< hashValue << std::endl;
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
            value.erase(std::remove(value.begin(), value.end(), '\n'), value.cend());
            value.erase(std::remove(value.begin(), value.end(), '\r'), value.cend());
            bloomFilter.insert(value);
        }
    }

    file.close();
}