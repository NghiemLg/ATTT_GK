#include "../../src/des.h"
#include "../../src/utils.h"
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Read key
    std::ifstream key_file("key.txt");
    std::string key_hex;
    std::getline(key_file, key_hex);
    auto key_bin = hex_to_bin(key_hex);
    if (key_bin.size() != 8) return 1; // Error
    Key key;
    std::copy(key_bin.begin(), key_bin.end(), key.begin());

    // Read ciphertext
    std::ifstream ciphertext_file("ciphertext.txt");
    std::string cipher_hex;
    std::getline(ciphertext_file, cipher_hex);
    auto cipher_bin = hex_to_bin(cipher_hex);
    if (cipher_bin.size() % 8 != 0) return 1; // Error

    // Decrypt
    Subkeys subkeys = des_key_schedule(key);
    std::vector<uint8_t> plaintext;
    for (size_t i = 0; i < cipher_bin.size(); i += 8) {
        Block block;
        std::copy(cipher_bin.begin() + i, cipher_bin.begin() + i + 8, block.begin());
        Block decrypted = des_decrypt_block(block, subkeys);
        plaintext.insert(plaintext.end(), decrypted.begin(), decrypted.end());
    }
    plaintext = unpad(plaintext);

    // Write plaintext
    std::ofstream decrypted_file("decrypted.txt", std::ios::binary);
    decrypted_file.write(reinterpret_cast<const char*>(plaintext.data()), plaintext.size());

    return 0;
}