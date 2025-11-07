#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& arr) {
    vector<int> result;
    stack<int> s;

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() >= arr[i])
            s.pop(); // Remove elements >= current

        if (s.empty())
            result.push_back(-1); // No smaller element
        else
            result.push_back(s.top()); // Top is nearest smaller

        s.push(arr[i]); // Push current element
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> nsl = nearestSmallerToLeft(arr);

    cout << "Nearest smaller to left: ";
    for (int val : nsl)
        cout << val << " ";
    cout << endl;

    return 0;
}