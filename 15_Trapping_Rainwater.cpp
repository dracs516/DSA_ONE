#include <iostream>
using namespace std;

int rainwater_trap(int arr[], int n)
{
    int left[n], right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the no. of building blocks: ";
    cin >> n;
    int arr[n];
    cout << "Enter the height of each building: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The amount of rainwater that can be stored is: " << rainwater_trap(arr, n) << " blocks." << endl;
    return 0;
}