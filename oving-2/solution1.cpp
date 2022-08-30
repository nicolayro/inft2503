#include <iostream>

int main() {
    int i = 3; // 3
    int j = 5; // 3
    int *p = &i; // Pointer to location of 'i' int memory
    int *q = &j; // Pointer to location of 'j' in memory

    std::cout << "i\tval: " << i << "\t\t\tpt: " << &i << std::endl;
    std::cout << "j\tval: " << j << "\t\t\tpt: " << &j << std::endl;
    std::cout << "p\tval: " << p << "\tpt: " << &p << std::endl;
    std::cout << "q\tval: " << q << "\tpt: " << &q << std::endl;

    *p = 7; // 'i', the variable p is pointing to, is set to 7
    *q += 4; // the variable 'q' is pointing to is incremented by 4 ()
    *q = *p + 1; // q is set to the value 'p' is pointing to plus 1 (8)
    p = q; // The pointer p is now also pointing to j

    std::cout << "i\tval: " << i << "\t\t\tpt: " << &i << std::endl;
    std::cout << "j\tval: " << j << "\t\t\tpt: " << &j << std::endl;
    std::cout << "p\tval: " << p << "\tpt: " << &p << std::endl;
    std::cout << "q\tval: " << q << "\tpt: " << &q << std::endl;
    std::cout << "*p\tval: " << *p << std::endl;

    return 0;
}
