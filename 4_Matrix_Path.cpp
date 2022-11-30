#include <iostream>
using namespace std;

int getPaths(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    return getPaths(n - 1, m) + getPaths(n, m - 1);
}

int main()
{
    int n, m;
    cout << "Enter the no. of rows and columns: ";
    cin >> n >> m;

    cout << "No. of paths from Matrix[0,0] to Matrix[" << n << "," << m << "] using R and B moves only is: " << getPaths(n, m) << endl;
}