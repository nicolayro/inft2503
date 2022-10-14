#include <iostream>

using namespace std;

template<typename T, typename G>
class Pair{
public:
    T first;
    G second;
    Pair(T first, G second) : first(first), second(second) {}

    Pair operator+(const Pair &other) {
        Pair pair = *this;
        pair.first += other.first;
        pair.second += other.second;
        return pair;
    }

    bool operator>(const Pair &other) {
        auto sum1 = first + second;
        auto sum2 = other.first + other.second;
        return sum1 > sum2;
    }
};

int main() {
// Klassen Pair forutsetter at typene har '+' og '>' operatorene implementert.
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}
