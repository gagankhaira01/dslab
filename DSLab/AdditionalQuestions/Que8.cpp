#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1); // initialize all to -1
    stack<int> s; // store indices of elements

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            nge[s.top()] = arr[i]; // arr[i] is next greater for arr[s.top()]
            s.pop();
        }
        s.push(i); // push current index
    }

    return nge;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> nge = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int val : nge)
        cout << val << " ";
    cout << endl;

    return 0;
}