#include "bitstring.h"
#include <stdexcept>
#include <algorithm>

BitString::BitString() {}

BitString::BitString(const std::string& str) {
    for (char c : str) {
        if (c == '0') {
            bits.push_back(0);
        } else if (c == '1') {
            bits.push_back(1);
        } else {
            throw std::invalid_argument("Битовая строка может содержать только 0 и 1");
        }
    }
}

BitString::BitString(const BitString& other) {
    bits = other.bits;
}

BitString::~BitString() {}

BitString BitString::AND(const BitString& other) const {
    BitString result;
    size_t max_len = std::max(bits.size(), other.bits.size());

    for (size_t i = 0; i < max_len; i++) {
        unsigned char bit1 = (i < bits.size()) ? bits[i] : 0;
        unsigned char bit2 = (i < other.bits.size()) ? other.bits[i] : 0;
        result.bits.push_back(bit1 & bit2);
    }

    return result;
}

BitString BitString::OR(const BitString& other) const {
    BitString result;
    size_t max_len = std::max(bits.size(), other.bits.size());

    for (size_t i = 0; i < max_len; i++) {
        unsigned char bit1 = (i < bits.size()) ? bits[i] : 0;
        unsigned char bit2 = (i < other.bits.size()) ? other.bits[i] : 0;
        result.bits.push_back(bit1 | bit2);
    }

    return result;
}

BitString BitString::XOR(const BitString& other) const {
    BitString result;
    size_t max_len = std::max(bits.size(), other.bits.size());

    for (size_t i = 0; i < max_len; i++) {
        unsigned char bit1 = (i < bits.size()) ? bits[i] : 0;
        unsigned char bit2 = (i < other.bits.size()) ? other.bits[i] : 0;
        result.bits.push_back(bit1 ^ bit2);
    }

    return result;
}

BitString BitString::NOT() const {
    BitString result;

    for (unsigned char bit : bits) {
        result.bits.push_back(bit ^ 1);
    }

    return result;
}

std::string BitString::toString() const {
    std::string result;
    for (unsigned char bit : bits) {
        result += (bit == 0) ? '0' : '1';
    }
    return result;
}

size_t BitString::length() const {
    return bits.size();
}