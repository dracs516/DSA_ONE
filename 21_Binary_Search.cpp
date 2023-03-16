#include <iostream>
#include <vector>
using namespace std;

int main()
{˛
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    cout << "Original Array:" << endl;
    printArray(arr, n);

    
    cout << "Sorted Array: " << endl;
    printArray(arr, n);
}