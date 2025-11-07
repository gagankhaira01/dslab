#include <iostream>
#include <string>

bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    std::string str1, str2;
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);

    std::string concatenated = str1 + str2;
    std::cout << "\n(a) Concatenated string: " << concatenated << std::endl;

    std::string reversed = "";
    for (int i = concatenated.length() - 1; i >= 0; i--)
        reversed += concatenated[i];
    std::cout << "(b) Reversed string: " << reversed << std::endl;

    std::string noVowels = "";
    for (int i = 0; i < concatenated.length(); i++)
        if (!isVowel(concatenated[i]))
            noVowels += concatenated[i];
    std::cout << "(c) String without vowels: " << noVowels << std::endl;

    std::string toSort = concatenated;
    for (int i = 0; i < toSort.length() - 1; i++) {
        for (int j = i + 1; j < toSort.length(); j++) {
            if (toSort[i] > toSort[j]) {
                char temp = toSort[i];
                toSort[i] = toSort[j];
                toSort[j] = temp;
            }
        }
    }
    std::cout << "(d) Sorted string: " << toSort << std::endl;

    std::string lower = concatenated;
    for (int i = 0; i < lower.length(); i++) {
        if (lower[i] >= 'A' && lower[i] <= 'Z')
            lower[i] = lower[i] + 32;
    }
    std::cout << "(e) Lowercase string: " << lower << std::endl;

    return 0;
}
