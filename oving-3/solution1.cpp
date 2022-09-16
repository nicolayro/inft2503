#include <iostream>

const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;
 private:
    double radius;
};

// ==> Implementasjon av klassen Circle
//
Circle::Circle(double radius_) : radius(radius_) {}

double Circle::get_area() const {
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    return 2.0 * pi * radius;
}

int main() {
    Circle circle(10.0);
    std::cout << "Area: " << circle.get_area() << std::endl;
    std::cout << "Circumference: " << circle.get_circumference() << std::endl;

    return 0;
}
