#include <iostream>
#include <algorithm>
#include <vector>


std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

void task_a(const std::vector<int> v) {
    int n = 15;
    auto pos = std::find_if(v.begin(), v.end(), [n](int i) {
            return i > n;
    });
    if (pos != std::end(v)) {
        std::cout << "first element larger than " << n;
        std::cout << ": " << *pos << std::endl;
    } else {
        std::cout << "no element larger than " << n << std::endl;;
    }
}

void task_b(const std::vector<int> v1, const std::vector<int> v2) {
    bool equal1 = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i, int j) {
                return abs(i-j) <= 2;
            });
    std::cout << "[v1.begin(), v1.begin() + 5> == v2: " << equal1 << std::endl;

    bool equal2 =  std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i, int j) {
                return abs(i-j) <= 2;
            });
    std::cout << "[v1.begin(), v1.begin() + 4> == v2: " << equal2 << std::endl;

}

void task_c(const std::vector<int> v) {
    std::vector<int> new_v(v.size());
    std::replace_copy_if(v.begin(), v.end(), new_v.begin(), [](int i) {
                return i % 2 != 0;
            }, 100);
    std::cout << "v1, but odd nums are 100: " << new_v << std::endl;
}


int main(int argc, char* argv[]) {
    std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    std::cout << "v1: " << v1 << std::endl;
    std::vector<int> v2 = {2, 3, 12, 14, 24};
    std::cout << "v2: " << v2 << std::endl;

    std::cout << "a)" << std::endl;
    task_a(v1);

    std::cout << "b)" << std::endl;
    task_b(v1, v2);

    std::cout << "c)" << std::endl;
    task_c(v1);

    return 0;
}
