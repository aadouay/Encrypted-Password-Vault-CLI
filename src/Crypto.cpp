#include "Crypto.hpp"

std::string Crypto::encrypt(const std::string& data, const std::string& key){
    const int MIN_PRINT = 32;   // first printable char
    const int MAX_PRINT = 126;  // last printable char
    const int RANGE = MAX_PRINT - MIN_PRINT + 1;

    int key_shift1 = (static_cast <int> (key[0]) % 26);
    int key_shift2 = (static_cast <int> (key[key.length() - 1]) % 26);
    std::string encrypted_pass;

    // Encrypt the data using a key shift1 and shift2
    for (size_t i = 0; i < data.size(); i++){
        encrypted_pass += MIN_PRINT + ((data[i] - MIN_PRINT + key_shift1) % RANGE);
    }

    for (size_t i = 0; i < encrypted_pass.size(); i++){
        encrypted_pass[i] = MIN_PRINT + ((encrypted_pass[i] - MIN_PRINT + key_shift2) % RANGE);
    }

    // reverse the encrypted string
    std::reverse(encrypted_pass.begin(), encrypted_pass.end());
    return encrypted_pass;
}

std::string Crypto::decrypt(const std::string& encryptedData, const std::string& key){
    const int MIN_PRINT = 32;   // first printable char
    const int MAX_PRINT = 126;  // last printable char
    const int RANGE = MAX_PRINT - MIN_PRINT + 1;

    int key_shift1 = (static_cast <int> (key[0]) % 26);
    int key_shift2 = (static_cast <int> (key[key.length() - 1]) % 26);
    std::string decrypted_pass = encryptedData;

    // reverse the encrypted string
    std::reverse(decrypted_pass.begin(), decrypted_pass.end());

    // Decrypt the data using key shifts
    for (size_t i = 0; i < decrypted_pass.size(); i++){
        decrypted_pass[i] = MIN_PRINT + ((decrypted_pass[i] - MIN_PRINT - key_shift2 + RANGE) % RANGE);
    }

    for (size_t i = 0; i < decrypted_pass.size(); i++){
        decrypted_pass[i] = MIN_PRINT + ((decrypted_pass[i] - MIN_PRINT - key_shift1 + RANGE) % RANGE);
    }

    return decrypted_pass;
}
