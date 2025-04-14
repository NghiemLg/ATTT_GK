#include "../../src/aes.h"
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
    if (key_bin.size() != 16) return 1; // Error
    Key key;
    std::copy(key_bin.begin(), key_bin.end(), key.begin());

    // Read plaintext
    std::ifstream plaintext_file("plaintext.txt", std::ios::binary);
    std::vector<uint8_t> plaintext((std::istreambuf_iterator<char>(plaintext_file)),
                                   std::istreambuf_iterator<char>());

    // Pad and encrypt
    auto padded = pad(plaintext, 16);
    ExpandedKey expanded_key = aes_key_expansion(key);
    std::vector<uint8_t> ciphertext;
    for (size_t i = 0; i < padded.size(); i += 16) {
        Block block;
        std::copy(padded.begin() + i, padded.begin() + i + 16, block.begin());
        Block encrypted = aes_encrypt_block(block, expanded_key);
        ciphertext.insert(ciphertext.end(), encrypted.begin(), encrypted.end());
    }

    // Write ciphertext
    std::ofstream ciphertext_file("ciphertext.txt");
    ciphertext_file << bin_to_hex(ciphertext);

    return 0;
}