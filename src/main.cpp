#include <iostream>
#include "bitstring.h"

int main() {
    std::cout << "=== BitString Operations ===" << std::endl;

    std::string input1, input2;

    std::cout << "Enter first bit string: ";
    std::cin >> input1;

    std::cout << "Enter second bit string: ";
    std::cin >> input2;

    try {
        BitString bs1(input1);
        BitString bs2(input2);

        std::cout << "AND: " << bs1.AND(bs2).toString() << std::endl;
        std::cout << "OR:  " << bs1.OR(bs2).toString() << std::endl;
        std::cout << "XOR: " << bs1.XOR(bs2).toString() << std::endl;
        std::cout << "NOT1: " << bs1.NOT().toString() << std::endl;
        std::cout << "NOT2: " << bs2.NOT().toString() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}