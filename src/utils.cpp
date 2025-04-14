#include "utils.h"
#include <stdexcept>

std::vector<uint8_t> hex_to_bin(const std::string& hex) {
    std::vector<uint8_t> bin;
    if (hex.length() % 2 != 0) throw std::runtime_error("Invalid hex string length");
    for (size_t i = 0; i < hex.length(); i += 2) {
        uint8_t byte = (uint8_t)std::stoi(hex.substr(i, 2), nullptr, 16);
        bin.push_back(byte);
    }
    return bin;
}

std::string bin_to_hex(const std::vector<uint8_t>& bin) {
    std::string hex;
    for (uint8_t byte : bin) {
        char buf[3];
        sprintf(buf, "%02x", byte);
        hex += buf;
    }
    return hex;
}

std::vector<uint8_t> pad(const std::vector<uint8_t>& data, size_t block_size) {
    std::vector<uint8_t> padded = data;
    size_t pad_len = block_size - (data.size() % block_size);
    if (pad_len == block_size) pad_len = block_size; // Add full block if exact multiple
    for (size_t i = 0; i < pad_len; i++) {
        padded.push_back(static_cast<uint8_t>(pad_len));
    }
    return padded;
}

std::vector<uint8_t> unpad(const std::vector<uint8_t>& data) {
    if (data.empty()) return data;
    uint8_t pad_len = data.back();
    if (pad_len > data.size() || pad_len == 0) throw std::runtime_error("Invalid padding");
    for (size_t i = data.size() - pad_len; i < data.size(); i++) {
        if (data[i] != pad_len) throw std::runtime_error("Invalid padding bytes");
    }
    return std::vector<uint8_t>(data.begin(), data.end() - pad_len);
}