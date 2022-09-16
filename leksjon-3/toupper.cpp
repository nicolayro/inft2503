#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string word;
    
    std::cout << "Please write a word, stop with 'x':" << std::endl;

    std::cin >> word;

    while (word != "x" && word != "X") {
        for (size_t i = 0; i < word.length(); i++) {
            word[i] = std::toupper(word[i]);
        }

        std::cout << "Uppercase: " << word << std::endl;
        std::cin >> word;
    }
    return 0;
}
