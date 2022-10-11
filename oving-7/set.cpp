#include <vector>
#include <iostream>
#include "set.hpp"

Set::Set() {}

bool Set::contains(int integer) const {
    return std::find(numbers.begin(), numbers.end(), integer) != numbers.end();
}

Set Set::operator+(const Set &other) const {
    Set set = *this;
    for (auto number: other.numbers) {
        set += number;
    }
    return set;
}

Set &Set::operator+=(int integer) {
    if (!contains(integer)) {
        numbers.push_back(integer);
    }
    return *this;
}
 
Set &Set::operator=(const Set &other) {
    numbers = other.numbers;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Set &set) {
    bool first = true;
    out << "{";
    for (auto &number : set.numbers) {
        if (first) {
            out << number;
            first = false;
        } else {
            out << ", " << number;
        }
    }
    out << "}";
    return out;
}

