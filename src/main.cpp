#include "Crypto.hpp"
#include <Utils.hpp>
#include <iostream>
#include <string>

int main(int ac, char** av) {
    std::cout << "Welcome to the Encrypted Password Vault CLI!" << std::endl;
    std::srand(std::time(NULL));
    if (ac != 4)
    {
        std::cout << "\n========================================\n";
        std::cout << "🔐  Encrypted Password Vault - Usage\n";
        std::cout << "========================================\n\n";

        std::cout << "📖 USAGE:\n";
        std::cout << "  ./password_vault <key> <value> <method>\n\n";

        std::cout << "⚙️ METHODS:\n";
        std::cout << "  ENC   🔒 Encrypt and store a password\n";
        std::cout << "  DEC   🔓 Decrypt a password using a serial ID\n\n";

        std::cout << "💡 EXAMPLES:\n";
        std::cout << "  Encrypt:\n";
        std::cout << "    ./password_vault Github AJASD1234!@#$ ENC\n\n";

        std::cout << "  Decrypt:\n";
        std::cout << "    ./password_vault Github <encrypted_value> DEC\n\n";

        std::cout << "📝 NOTE:\n";
        std::cout << "  - A serial ID is generated during encryption.\n";
        std::cout << "  - Use your external script with the serial ID\n";
        std::cout << "    before running the decryption process.\n\n";

        std::cout << "========================================\n";
        return 1;
    }


    std::string key = av[1];
    std::string value = av[2];
    std::string method = av[3];
    std::string encrypted;
    std::string decrypted;
    const std::string vaultPath = "data/vault.dat";
    //check method
    if(method == "ENC")
        encrypted = Crypto::encrypt(value, key);
    else if(method == "DEC")
        decrypted = Crypto::decrypt(value, key);
    else
       return (std::cout << "Invalid method. Use ENC for encryption or DEC for decryption." << std::endl), 1;
    
    // CHECK IF FILE vault.dat EXISTS, IF NOT CREATE IT
    if(!Utils::createFile(vaultPath)){
        std::cout << "Error creating vault file." << std::endl;
        return 1;
    }
    // APPEND TO FILE
    if(method == "ENC"){
        // generate serial IDs
        std::string serial_IDs = Utils::generateSerialIDs(5);
        // encrypt with custom algorithm to add more security
        encrypted = Utils::encreption_algorithm(encrypted, serial_IDs);
        // add to file
        if(!Utils::addToFile(vaultPath, key, encrypted, serial_IDs)){
            std::cout << "Error appending to vault file." << std::endl;
            return 1;
        }
        std::cout << "Encrypted value stored successfully." << std::endl;
    }
    else{
        std::cout << key << " | " << decrypted << std::endl;
        std::cout << "Decrypted value displayed successfully." << std::endl;
    }
    return 0;
}