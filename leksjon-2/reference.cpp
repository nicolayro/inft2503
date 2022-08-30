#include <iostream>


void zero(int *table, int length);

const int max_length = 10;

int main() {
    int table[max_length];
    zero(table, max_length);

    return 0;
}

/**
 * Fills a table with zeroes
 */
void zero(int *table, int length) {
    for (int i = 0; i < length; i++) {
        table[i] = 0;
    }
}
