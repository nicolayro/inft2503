#include <iostream>

int find_sum(const int *table, int length);

int main() {
    // Declare variables
    const int LENGTH = 20;
    int numbers[LENGTH];
    int *table = numbers; // We keep the pointer to the first element
    
    // Initialize array with values 1, 2, 3... length
    for (int i = 0; i < LENGTH; i++) {
        numbers[i] = i + 1;
    }

    int first = find_sum(table, 10);

    // We call the function not with the actual table but with
    // the reference to the beginning. Then, we effectively move the beginning
    // with pointer arithmetic.
    table += 10;
    int next = find_sum(table, 5);

    table += 5;
    int last = find_sum(table, 5);

    std::cout << "First 10: " << first << std::endl;
    std::cout << "Next 5: " << next << std::endl;
    std::cout << "Last 5: " << last << std::endl;

    return 0;
}

int find_sum(const int *table, int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += *table;
        table += 1;
    }
    return total;
}
