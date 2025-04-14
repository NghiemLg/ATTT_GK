#ifndef DES_H
#define DES_H

#include <array>
#include <cstdint>

using Block = std::array<uint8_t, 8>;
using Key = std::array<uint8_t, 8>;
using Subkeys = std::array<std::array<uint8_t, 6>, 16>;

Subkeys des_key_schedule(const Key& key);
Block des_encrypt_block(const Block& block, const Subkeys& subkeys);
Block des_decrypt_block(const Block& block, const Subkeys& subkeys);

#endif