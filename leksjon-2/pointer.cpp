#include <iostream>

void foo(const int *bar);
int main() {
    int table[4];
    int *p = table;
    table[2] = 4;

    std::cout << "t2: " << table[2] << std::endl;

    p[2] = 5;

    std::cout << "t2: " << table[2] << std::endl;

    table[0] = 1;
    table[1] = 2;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "*(p + 1): " << *(p+1) << std::endl;


    /*
     * ----------------------------
     * Constant pointers
     * ----------------------------
     */

    foo(table);

    // A const pointer means the value the pointer is pointer to is immutable,
    // not the pointer itself. To define a constant pointer, do:
    int num = 6;
    int *const pointer= &num;
    std::cout << "const pointer val: " << *pointer << std::endl;
    // When the pointer is const, the value it's pointing to is still mutable
    num = 7;
    std::cout << "const pointer val: " << *pointer << std::endl;




    return 0;
}

void foo(const int *bar) {
    const int *evil = bar; // Pointer to const pointer must be const as well
}
