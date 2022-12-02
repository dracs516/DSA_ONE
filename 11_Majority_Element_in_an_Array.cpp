#include <iostream>

using namespace std;

bool check_majority(int arr[], int checkVal, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == checkVal)
            count++;
    }
    if (count > n / 2)
        return 1;
    else
        return 0;
}

int majority_element(int arr[], int n)
{
    int ansIndex = 0;
    int frequency = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[ansIndex])
            frequency++;
        else
            frequency--;

        if (frequency == 0)
        {
            ansIndex = i;
            frequency = 1;
        }
    }

    return arr[ansIndex];
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >>
            arr[i];

    int checkVal = majority_element(arr, n);
    if (check_majority(arr, checkVal, n))
        cout << "Majority element is: " << checkVal << endl;
    else
        cout << "No majority element in the array" << endl;

    return 0;
}