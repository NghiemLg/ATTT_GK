#include "aes.h"

ExpandedKey aes_key_expansion(const Key& key) {
    // Implement AES-128 key expansion
    ExpandedKey expanded; // Placeholder
    expanded[0] = key;
    return expanded;
}

Block aes_encrypt_block(const Block& block, const ExpandedKey& expanded_key) {
    // Implement AES encryption: 10 rounds (SubBytes, ShiftRows, MixColumns, AddRoundKey)
    Block output = block; // Placeholder
    return output;
}

Block aes_decrypt_block(const Block& block, const ExpandedKey& expanded_key) {
    // Implement AES decryption: 10 inverse rounds
    Block output = block; // Placeholder
    return output;
}