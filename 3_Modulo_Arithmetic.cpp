#include <iostream>
using namespace std;

int normal_power(int n, int pow)
{
    int res = 1;
    while (pow > 0)
    {
        // if (pow % 2 != 0) ----> Modulo operation is expensive so we will use Bit manipulation here
        if (pow & 1 != 0)
        {
            res = res * n;
        }
        n = n * n;
        // pow = pow / 2; ------> Divide is expensive so right shift by 1 to divide by 2
        pow = pow >> 1;
    }
    return res;
}

// This function will return the value of a^b i.e. n^pow
long fast_power(long a, long b, int n)
{
    long res = 1;
    while (b > 0)
    {
        // if (pow % 2 != 0) ----> Modulo operation is expensive so we will use Bit manipulation here
        if (b & 1 != 0)
        {
            // res = (res % n * a % n) % n; --------> We can omit the % n in the res term as anyhow it is wholly being % by n at the end so that means that res will never excede n. But dont know proper reason here
            res = (res * a % n) % n;
        }
        a = a % n * a % n;
        // pow = pow / 2; ------> Divide is expensive so right shift by 1 to divide by 2
        b = b >> 1;
    }
    return res;
    // return n % 2 == 0 ? fast_power(n ^ 2, pow / 2) : n * fast_power(n, pow - 1); --------> Dont know why not used....didnt try also
}

int main()
{
    cout << "Normal power: " << normal_power(3978432, 5) << endl
         << "Fast power: " << fast_power(3978432, 5, 1000000007) << endl;
    return 0;
}