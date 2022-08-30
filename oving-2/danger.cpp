#include <iostream>

int main() {
    char text[5];
    char *pointer = text;
    char search_for = 'e';
    std::cin >> text;
    std::cout << &pointer << std::endl;

    while (*pointer != search_for) {
        *pointer = search_for;
        pointer++;
    }

    std::cout << *pointer << std::endl;
    std::cout << &pointer << std::endl;

    return 0;
}
