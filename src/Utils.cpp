#include "Utils.hpp"
#include <cstdlib>
#include <ctime>

bool Utils::createFile(const std::string& filename) {
    std::ofstream file(filename.c_str(), std::ios::app);
    if (!file) {
        return false;
    }
    file.close();
    return true;
}

bool Utils::addToFile(const std::string& file_name, const std::string& key, const std::string& encrypted_value, std::string serial_ID){
    std::ofstream file(file_name.c_str(), std::ios::app);
    if(!file.is_open())
        return false;
    // check if file is empty to write header
    std::ifstream check(file_name.c_str());
    if (check.peek() == std::ifstream::traits_type::eof()) {
        file << "KEY | ENCRYPTED_VALUE" << std::endl;
        file << "----------------------" << std::endl;
    }
    check.close();
    // add new line for the new entry
    file << key << " | " << encrypted_value;
    bool start_ID = false;
    for(size_t i = 0; i < serial_ID.size(); i++){
        if(!start_ID){
            file << "ID";
            start_ID = true;
        }
        file << serial_ID[i];
    }
    file << std::endl;
    return true;
}

std::string Utils::encreption_algorithm(const std::string& value, std::string serial_ID) {

    std::string encrypted;
    encrypted.reserve(value.size());

    for (size_t i = 0; i < value.size(); i++)
    {
        size_t index_id = 0;
        int c = value[i] - 32;
        if(index_id >= serial_ID.size())
            index_id = 0;
        int k = (static_cast<int>(serial_ID[index_id]) + i * 31) % 95;
        int e = ((c + k) * (c + k)) % 95;
        encrypted += static_cast<char>(e + 32);
        index_id++;
    }

    return encrypted;
}

std::string  Utils::generateSerialIDs(size_t length) {
    std::string serial_IDs;
    for (size_t i = 0; i < length; ++i) {
        char random_char = static_cast <char> (32 + std::rand() % 95);
        serial_IDs += random_char;
    }
    return serial_IDs;
}