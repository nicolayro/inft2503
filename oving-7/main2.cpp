#include <iostream>
#include "set.hpp"

int main() {
    // Create empty set
    Set set;
    std::cout << "Empty set: " << set << std::endl;

    // Add integer to set
    set += 1;
    set += 2;
    set += 3; 
    std::cout << "Populated set: " << set << std::endl;

    set += 1; // Check that duplicates aren't added!
    std::cout << "Populated set: " << set << std::endl;

    // Find union of set (also set a set to be another set)
    Set set2;
    set2 += 3;
    set2 += 4;
    set2 += 5;
    std::cout << "Second set: " << set2 << std::endl;

    set = set + set2;
    std::cout << "Union of the sets: " << set << std::endl;


    return 0;
}
