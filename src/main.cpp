#include <iostream>
#include <limits>
#include "bitstring.h"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getBitStringInput(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (std::cin >> input) {
            bool valid = true;
            for (char c : input) {
                if (c != '0' && c != '1') {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                clearInputBuffer();
                return input;
            } else {
                std::cout << "Ошибка! Битовая строка может содержать только 0 и 1.\n";
                clearInputBuffer();
            }
        } else {
            std::cout << "Ошибка ввода! Попробуйте снова.\n";
            clearInputBuffer();
        }
    }
}

int main() {
    std::cout << "РАБОТА С БИТОВЫМИ СТРОКАМИ" << std::endl;

    try {
        std::string input1 = getBitStringInput("Введите первую битовую строку: ");
        std::string input2 = getBitStringInput("Введите вторую битовую строку: ");

        BitString bs1(input1);
        BitString bs2(input2);

        std::cout << "\nРЕЗУЛЬТАТЫ" << std::endl;
        std::cout << "Битовая строка 1: " << bs1.toString() << std::endl;
        std::cout << "Битовая строка 2: " << bs2.toString() << std::endl;

        BitString and_result = bs1.AND(bs2);
        BitString or_result = bs1.OR(bs2);
        BitString xor_result = bs1.XOR(bs2);
        BitString not1_result = bs1.NOT();
        BitString not2_result = bs2.NOT();

        std::cout << "AND: " << and_result.toString() << std::endl;
        std::cout << "OR:  " << or_result.toString() << std::endl;
        std::cout << "XOR: " << xor_result.toString() << std::endl;
        std::cout << "NOT первой строки: " << not1_result.toString() << std::endl;
        std::cout << "NOT второй строки: " << not2_result.toString() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}