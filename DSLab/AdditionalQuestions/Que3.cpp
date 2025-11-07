#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int freq[26] = {0};  // Assuming lowercase English letters

    // Count characters in str1
    for (char c : str1)
        freq[c - 'a']++;

    // Subtract character counts using str2
    for (char c : str2)
        freq[c - 'a']--;

    // If all counts are zero, strings are anagrams
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return false;

    return true;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "The strings are anagrams." << endl;
    else
        cout << "The strings are not anagrams." << endl;

    return 0;
}