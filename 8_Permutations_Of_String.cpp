#include <iostream>
#include <string>

using namespace std;

void permutaion(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        permutaion(str, l + 1, r);
        swap(str[l], str[i]);
    }
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << "The permutations are: " << endl;
    permutaion(str, 0, str.length() - 1);
    return 0;
}