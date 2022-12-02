#include <iostream>
using namespace std;

int kadene(int arr[], int n)
{
    int maxSum = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum > maxSum)
            maxSum = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "The max sum of contiguos subarray possible is: " << kadene(arr, n) << endl;
}