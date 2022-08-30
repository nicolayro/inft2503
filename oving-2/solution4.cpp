#include <iostream>

int main() {

    int a = 5;

    // Declaring reference without initializing
    // int &b;
    // Solution:
    int &b = a;

    int *c;
    c = &b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // a and b are not pointers, so they do not need to be dereferenced
    // *a = *b + *c;
    // Solution:
    a = b + *c;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // b is a reference to a, don't want to make b reference '2'.
    // &b = 2;
    // Solution:
    b = 2;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}
