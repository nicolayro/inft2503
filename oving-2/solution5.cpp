#include <iostream>

int main() {
    // Number with a pointer and a reference
    double number;
    double *pointer = &number;
    double &ref = number;

    // Method one
    number = 1;
    std::cout << number << std::endl;

    // Method two
    *pointer = 2;
    std::cout << number << std::endl;

    // Method three
    ref = 3;
    std::cout << number << std::endl;
    
    /* 
     * Output should be:
     *  1
     *  2
     *  3
     */
    return 0;
}
