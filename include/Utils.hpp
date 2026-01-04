#pragma once
#include <string>
#include <fstream>
#include <vector>

class Utils {
    public:
        static bool addToFile(const std::string& file_name, const std::string& key, const std::string& encrypted_value, std::string serial_ID);
        static bool createFile(const std::string& filename);
        static std::string encryption_algorithm(const std::string& value, std::string serial_ID);
        static std::string generateSerialIDs(size_t length);
};