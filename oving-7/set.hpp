#include <vector>

class Set {
private:
    std::vector<int> numbers;

    // Small helper funciton
    bool contains(int integer) const;
public:
    Set();
    Set(const Set &) = default;
    Set operator+(const Set &other) const;
    Set &operator+=(int integer);
    Set &operator=(const Set &other);

    friend std::ostream &operator<<(std::ostream &out, const Set &set);
};


