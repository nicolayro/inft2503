// Read a list of temperatures, and count amount frequency in the following
// intervals:
//      Below 10
//      10-20 (both including)
//      Above 20
//
// Also: No functions or tables

#include <iostream>

const int LENGTH = 5; // Number of temperaturer
const int LOW = 10;
const int HIGH = 20;

int main() {
    int below = 0;
    int between = 0;
    int above = 0;
    double number; // for storing user input

    std::cout << "Du skal skrive inn " << LENGTH << " temperaturer." << std::endl;
    for (int i = 0; i < LENGTH; i++) {
        std::cout << "Temperatur nr " << i + 1 << ": ";
        std::cin >> number;
        if (number < LOW) below++;
        else if (number > HIGH) above++;
        else between++;
    }
    std::cout << "Antall under " << LOW << " er: " << below << std::endl;
    std::cout << "Antall mellom " << LOW << " og " << HIGH << " er: " << between << std::endl;
    std::cout << "Antall over " << HIGH << " er: " << above << std::endl;

    return 0;
}
