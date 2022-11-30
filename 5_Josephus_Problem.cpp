#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main()
{
    cout << "Enter the no. of people and the value of k: ";
    int n, k;
    cin >> n >> k;
    cout << "The person remaining at the end is in 0-Based indexing is: " << josephus(n, k) << endl
         << "and 1-Based indexing is: " << josephus(n, k) + 1 << endl;
    return 0;
}