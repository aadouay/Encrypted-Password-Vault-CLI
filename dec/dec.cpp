#include <iostream>
#include <string>

void decryptAndPrint(const std::string& encrypted_data, const std::string& serial_ID) {
    std::string decrypted;

    size_t index = 0;

    for (size_t i = 0; i < encrypted_data.size(); i++)
    {
        int shift = static_cast<int>(serial_ID[index]);

        char c = encrypted_data[i];
        char dec = 32 + ((c - 32 - shift + 95) % 95);
        decrypted += dec;

        index++;
        if (index >= serial_ID.size())
            index = 0;
    }
    std::cout << "decrypted value is : " << decrypted << std::endl;
}

int main(int ac, char** av) {
    if (ac != 3) {
        std::cerr << "Usage: " << av[0] << " <input_string>" << std::endl;
        return 1;
    }
    std::string encrepted_data = av[1];
    std::string serial_ID = av[2];

    decryptAndPrint(encrepted_data, serial_ID);
    return 0;
}