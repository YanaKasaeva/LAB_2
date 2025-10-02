#ifndef BITSTRING_H
#define BITSTRING_H

#include <string>
#include <vector>
#include <stdexcept>

class BitString {
private:
    std::vector<unsigned char> bits;

public:
    BitString();
    BitString(const std::string& str);
    BitString(const BitString& other);
    ~BitString();

    BitString AND(const BitString& other) const;
    BitString OR(const BitString& other) const;
    BitString XOR(const BitString& other) const;
    BitString NOT() const;

    std::string toString() const;
    size_t length() const;
};

#endif