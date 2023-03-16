#include <iostream>
using namespace std;

void sieve_of_eratosthenes(int n, bool primeCheck[])
{
    for (int i = 2; i * i <= n; i++) // i < sqrrt(n) is enough too
    {
        for (int j = 2 * i; j <= n; j += i) // j += i will make it jump from 2 to 4 to 6 to 8.....or from 3 to 6 to 9 ....basically the multiples
        {
            primeCheck[j] = false;
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    bool primeCheck[n + 1];
    memset(primeCheck, true, sizeof(primeCheck));

    primeCheck[0] = false;
    primeCheck[1] = false;

    sieve_of_eratosthenes(n, primeCheck);

    for (int i = 0; i <= n; i++)
    {
        cout << endl
             << i << " " << primeCheck[i];
    }
    return 0;
}