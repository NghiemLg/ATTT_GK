#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <cstdint>

std::vector<uint8_t> hex_to_bin(const std::string& hex);
std::string bin_to_hex(const std::vector<uint8_t>& bin);
std::vector<uint8_t> pad(const std::vector<uint8_t>& data, size_t block_size);
std::vector<uint8_t> unpad(const std::vector<uint8_t>& data);

#endif