#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;

    while (1)
    {
        cin >> str;
        if (str == "0")
            return 0;

        int i;
        for (i = 0; i < str.length(); i++)
            if (str[i] != str[str.length() - 1 - i])
            {
                cout << "no\n";
                break;
            }
        if (i == str.length())
            cout << "yes\n";
    }
}