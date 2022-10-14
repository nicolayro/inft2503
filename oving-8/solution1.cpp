#include <iostream>
#include <string>

template<typename T>
bool equal(T a, T b) {
    std::cout << "(template)\t\t\t";
    return a == b;
}

bool equal(double a, double b) {
    double tol = 0.00001;
    std::cout << "(double)\t\t\t";
    return abs(a - b) < tol;
}

int main() {
    std::cout << "function\t\t\tstrategy\t\t\tresult" << std::endl;
    std::cout << "equal(1, 1):\t\t\t" << equal(1, 1) << std::endl;
    std::cout << "equal(1, 2):\t\t\t" << equal(1, 2) << std::endl;
    std::cout << "equal(0.1, 0.1):\t\t" << equal(0.1, 0.1) << std::endl;
    std::cout << "equal(0.1, 0.2):\t\t" << equal(0.1, 0.2) << std::endl;
    std::cout << "equal(0.000001, 0.000002):\t" << equal(0.000001, 0.000002) << std::endl;

    return 0;
}
