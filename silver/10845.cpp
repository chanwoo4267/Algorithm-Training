#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

queue<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> t;
            s.push(t);
        }
        else if (str == "pop")
        {
            if (s.empty())
                cout << "-1\n";
            else
            {
                cout << s.front() << "\n";
                s.pop();
            }
        }
        else if (str == "front")
        {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.front() << "\n";
        }
        else if (str == "back")
        {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.back() << "\n";
        }
        else if (str == "size")
            cout<<s.size()<<"\n";
        else if (str == "empty")
            cout<<s.empty()<<"\n";
    }
}