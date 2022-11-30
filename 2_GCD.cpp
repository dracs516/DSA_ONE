#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // if (a == 0)
    //     return b;
    // return gcd(b, a % b);
    return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of two numbers is: " << gcd(a, b) << endl;
    return 0;
}