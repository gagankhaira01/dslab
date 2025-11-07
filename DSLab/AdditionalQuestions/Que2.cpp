#include <iostream>
#include <string>
using namespace std;

// Function to check if part is substring of both x and y
bool isCommonSubstring(const string& part, const string& x, const string& y) {
    return x.find(part) != string::npos && y.find(part) != string::npos;
}

bool canSplitString(const string& s) {
    int n = s.length();
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, j - i);
            string part3 = s.substr(j);

            if (isCommonSubstring(part1, part2, part3) ||
                isCommonSubstring(part2, part1, part3) ||
                isCommonSubstring(part3, part1, part2)) {
                cout << "Split found: \"" << part1 << "\", \"" << part2 << "\", \"" << part3 << "\"\n";
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplitString(s)) {
        cout << "Yes, it's possible to split the string as required.\n";
    } else {
        cout << "No, it's not possible.\n";
    }

    return 0;
}
