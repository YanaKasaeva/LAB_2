#ifndef BITSTRING_H
#define BITSTRING_H

#include <string>

class BitString {
public:
    BitString();
    BitString(const std::string& str);

    BitString AND(const BitString& other) const;
    BitString OR(const BitString& other) const;
    BitString XOR(const BitString& other) const;
    BitString NOT() const;

    std::string toString() const;

private:
    std::string bits;
};

#endif