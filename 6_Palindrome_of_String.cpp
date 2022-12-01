#include <iostream>
#include <string>
using namespace std;

bool is_a_palindrome(string str, int l, int r)
{
    if (l >= r)
        return true;
    if (str[l] != str[r])
        return false;
    return is_a_palindrome(str, l + 1, r - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "The given string " << str << " is " << is_a_palindrome(str, 0, str.length()-1) << endl;
    return 0;
}