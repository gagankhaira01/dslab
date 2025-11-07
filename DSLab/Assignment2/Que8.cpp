#include <iostream>
using namespace std;

int main()
{

    int count = 0;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        bool dup_found = false;
        for (int j = i - 1; j > -1; j--)
        {
            if (arr[j] == arr[i])
            {
                dup_found = true;
                break;
            }
        }

        if (dup_found == false)
        {
            count++;
        }

    }

    cout << "There are "<< count << " unique elements in the array."<< endl;
    return 0;
}