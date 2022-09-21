#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    int number;
    std::cout << "Skriv positive tall (avslutt med 0): ";
    std::cin >> number;

    while (number > 0) {
        numbers.emplace_back(number);
        std::cin >> number;
    }

    std::cout << "Du har skrevet " << numbers.size() << " tall" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
