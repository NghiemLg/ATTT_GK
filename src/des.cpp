#include "des.h"

Subkeys des_key_schedule(const Key& key) {

    // Returns 16 subkeys, each 48 bits (6 bytes)
    Subkeys subkeys; // Placeholder
    return subkeys;
}

Block des_encrypt_block(const Block& block, const Subkeys& subkeys) {
    // Implement DES encryption: IP, 16 Feistel rounds, FP
    Block output = block; // Placeholder
    return output;
}

Block des_decrypt_block(const Block& block, const Subkeys& subkeys) {
    // Implement DES decryption: IP, 16 Feistel rounds (reverse subkeys), FP
    Block output = block; // Placeholder
    return output;
}