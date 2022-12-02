#include <iostream>
using namespace std;

int profit(int arr[], int n)
{
    int minTillNow = arr[0];
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minTillNow = min(minTillNow, arr[i]);
        int profit = arr[i] - minTillNow;
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
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

    cout << "The max profit is: " << profit(arr, n);
}