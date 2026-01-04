#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

class Crypto {
    public:
        static std::string encrypt(const std::string& data, const std::string& key);
        static std::string decrypt(const std::string& encryptedData, const std::string& key);
};
