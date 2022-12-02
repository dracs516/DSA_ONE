#include <iostream>
using namespace std;

int profit(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            profit += (arr[i] - arr[i - 1]);
    }
    return profit;
}

int main()
{
    int n;
    cout << "Enter the no. of days: ";
    cin >> n;
    int arr[n];
    cout << "Enter the stock prices for those days: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "The max profit is: " << profit(arr, n) << endl;
    return 0;
}