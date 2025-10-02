#include "bitstring.h"
#include <stdexcept>

BitString::BitString() : bits("") {}

BitString::BitString(const std::string& str) : bits(str) {
    for (char c : str) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Invalid bit string");
        }
    }
}

BitString BitString::AND(const BitString& other) const {
    std::string result;
    size_t max_len = std::max(bits.length(), other.bits.length());

    for (size_t i = 0; i < max_len; i++) {
        char bit1 = (i < bits.length()) ? bits[i] : '0';
        char bit2 = (i < other.bits.length()) ? other.bits[i] : '0';

        if (bit1 == '1' && bit2 == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }

    return BitString(result);
}

BitString BitString::OR(const BitString& other) const {
    std::string result;
    size_t max_len = std::max(bits.length(), other.bits.length());

    for (size_t i = 0; i < max_len; i++) {
        char bit1 = (i < bits.length()) ? bits[i] : '0';
        char bit2 = (i < other.bits.length()) ? other.bits[i] : '0';

        if (bit1 == '1' || bit2 == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }

    return BitString(result);
}

BitString BitString::XOR(const BitString& other) const {
    std::string result;
    size_t max_len = std::max(bits.length(), other.bits.length());

    for (size_t i = 0; i < max_len; i++) {
        char bit1 = (i < bits.length()) ? bits[i] : '0';
        char bit2 = (i < other.bits.length()) ? other.bits[i] : '0';

        if (bit1 != bit2) {
            result += '1';
        } else {
            result += '0';
        }
    }

    return BitString(result);
}

BitString BitString::NOT() const {
    std::string result;
    for (char bit : bits) {
        if (bit == '1') {
            result += '0';
        } else {
            result += '1';
        }
    }
    return BitString(result);
}

std::string BitString::toString() const {
    return bits;
}