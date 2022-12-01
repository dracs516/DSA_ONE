#include <iostream>
#include <string>

using namespace std;

void powerset(string str, int i, string cur)
{
    if (i == str.length())
    {
        cout << cur << endl;
        return;
    }
    powerset(str, i + 1, cur + str[i]);
    powerset(str, i + 1, cur);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "The powerset of " << str << " is : " << endl;
    powerset(str, 0, "");
}