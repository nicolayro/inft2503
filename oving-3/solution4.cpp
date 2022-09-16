#include <iostream>
#include <string>

int main() {
    // ====== a =======
    std::cout << "====== a =======" << std::endl; 
    std::string word1, word2, word3;

    std::cout << "Ord 1: ";
    std::cin >> word1;

    std::cout << "Ord 2: ";
    std::cin >> word2;

    std::cout << "Ord 3: ";
    std::cin >> word3;

    // ====== b =======
    std::string sentence = word1 + " " + word2 + " " + word3 + ".";
    std::cout << "====== b =======" << std::endl; 
    std::cout << "sentence: " << sentence << std::endl;

    // ====== c =======
    std::cout << "====== c =======" << std::endl; 
    std::cout << "Length word 1: " << word1.length() << std::endl;
    std::cout << "Length word 2: " << word2.length() << std::endl;
    std::cout << "Length word 3: " << word3.length() << std::endl;
    std::cout << "Length sentence : " << sentence.length() << std::endl;

    // ====== d =======
    std::string sentence2 = sentence;

    // ====== e =======
    for (int i = 9; i < 12; i++) {
        if (!sentence2[i]) {
            break;
        }
        sentence2[i] = 'x';
    }
    std::cout << "====== e =======" << std::endl; 
    std::cout << "sentence: " << sentence << std::endl;
    std::cout << "sentence2: " << sentence2 << std::endl;

    // ====== f =======
    std::string sentence_start;
    for (int i = 0; i < 5; i++) {
        if (!sentence[i]) {
            break;
        }
        sentence_start += sentence[i];
    }
    std::cout << "====== f =======" << std::endl; 
    std::cout << "sentence: " << sentence << std::endl;
    std::cout << "sentence_start: " << sentence_start << std::endl;

    // ====== g =======
    std::cout << "====== g =======" << std::endl; 
    std::cout << "includes 'hallo': " << (sentence.find("hallo") != std::string::npos) << std::endl;

    // ====== h =======
    size_t pos = 0;
    int occurences = 0;
    while ((pos = sentence.find("er", pos)) != std::string::npos) {
        occurences++;
        pos += 2; // If we find 'er', move to the position 
                  // after 'er' and continue looking
    }
    std::cout << "====== h =======" << std::endl; 
    std::cout << "Occurences of 'er': " << occurences << std::endl;

    return 0;
}
