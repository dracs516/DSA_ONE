#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int mid, int r)
{
    int leftSubArrayLength = mid - l + 1;
    int rightSubArrayLength = r - mid;

    int leftArray[leftSubArrayLength];
    int rightArray[rightSubArrayLength];

    for (int i = 0; i < leftSubArrayLength; i++)
    {
        leftArray[i] = arr[i + l];
    }

    for (int i = 0; i < rightSubArrayLength; i++)
    {
        rightArray[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < leftSubArrayLength && j < rightSubArrayLength)
    {
        if (leftArray[i] < rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }

    while (i < leftSubArrayLength)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSubArrayLength)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Original Array:" << endl;
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted Array: " << endl;
    printArray(arr, n);
}