#ifndef AES_H
#define AES_H

#include <array>
#include <cstdint>

using Block = std::array<uint8_t, 16>;
using Key = std::array<uint8_t, 16>;
using ExpandedKey = std::array<Block, 11>; // 10 rounds + initial key

ExpandedKey aes_key_expansion(const Key& key);
Block aes_encrypt_block(const Block& block, const ExpandedKey& expanded_key);
Block aes_decrypt_block(const Block& block, const ExpandedKey& expanded_key);

#endif