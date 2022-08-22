#include "temperature.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

const int LENGTH = 5;
const int LOW = 10;
const int HIGH = 20;

int main() {
    double temperatures[LENGTH];
   
    read_temperatures(temperatures, LENGTH);

    int below = 0;
    int between = 0;
    int above = 0;
    for (int i = 0; i < LENGTH; i++) { 
        int number = temperatures[i];
        if (number < LOW) below++;
        else if (number > HIGH) above++;
        else between++;
    }
    std::cout << "Antall under " << LOW << " er: " << below << std::endl;
    std::cout << "Antall mellom " << LOW << " og " << HIGH << " er: " << between << std::endl;
    std::cout << "Antall over " << HIGH << " er: " << above << std::endl;

    return 0;
}

void read_temperatures(double temperatures[], int length) {
    // Read file
    const char filename[] = "../temperatures.dat";
    std::ifstream file;
    file.open(filename);

    if (!file) {
        std::cout << "Kunne ikke åpne fil" << std::endl;
        exit(EXIT_FAILURE);
    }

    int number;
    for (int i = 0; i < length ; i++) {
        file >> number; // Read number
        temperatures[i] = number; 
    }
    file.close();
}
