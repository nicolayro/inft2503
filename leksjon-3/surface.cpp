#include <string>
#include <iostream>

class Surface {
private:
    std::string name;
    double length;
    double width;
public:
    Surface(const std::string &name_, double length_, double width_);
    const std::string &get_name() const;
    double get_length();
    double get_width();
    double get_area();
    double get_circumference();
};

Surface::Surface(const std::string &name_, double length_, double width_) : name(name_), length(length_), width(width_) {
}

const std::string &Surface::get_name() const{
    return name;
}

double Surface::get_length() {
    return length;
}

double Surface::get_width() {
    return width;
}

double Surface::get_area() {
    return length * width;
}

double Surface::get_circumference() {
    return 2 * (length + width);
}


int main() {
    Surface desk("Nicolay's pult", 60, 180);

    std::string name = desk.get_name();
    double width = desk.get_width();
    double length = desk.get_length();
    double area = desk.get_area();
    double circumference = desk.get_circumference();

    std::cout << "Name: " << name << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;

    return 0;
}


