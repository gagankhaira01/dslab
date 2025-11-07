#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;
    int n = students.size();

    // Count preferences
    for (int s : students) {
        if (s == 0) count0++;
        else count1++;
    }

    for (int s : sandwiches) {
        if (s == 0) {
            if (count0 > 0) count0--;
            else break; // no student wants circular sandwich
        } else {
            if (count1 > 0) count1--;
            else break; // no student wants square sandwich
        }
    }

    return count0 + count1; // remaining students
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> students(n), sandwiches(n);
    cout << "Enter students' preferences (0-circular, 1-square): ";
    for (int i = 0; i < n; i++) cin >> students[i];

    cout << "Enter sandwiches stack (top to bottom): ";
    return 0;
}