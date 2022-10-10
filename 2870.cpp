#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comp(string str1, string str2)
{
    if (str1.size() == str2.size())
        return str1 < str2;
    else
        return str1.size() < str2.size();
}

int main()
{
    int t;
    vector<string> v;
    string str, num;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (isdigit(str[j]))
                num += str[j];
            else if (!num.empty()) // num is non-empty and non-digit appears, insert into vector
            {
                while (num.length() >= 2 && num[0] == '0')
                    num.erase(0, 1);
                v.push_back(num);
                num = "";
            }
        }
        if (!num.empty()) // string end, so insert
        {
            while (num.length() >= 2 && num[0] == '0')
                num.erase(0, 1);
            v.push_back(num);
            num = "";
        }
    }
    sort(v.begin(), v.end(), comp);
    for (auto x : v)
        cout << x << endl;
}