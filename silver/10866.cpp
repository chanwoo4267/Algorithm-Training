#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

deque<int> s;

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
        if (str == "push_front")
        {
            cin >> t;
            s.push_front(t);
        }
        else if (str == "push_back")
        {
            cin >> t;
            s.push_back(t);
        }
        else if (str == "pop_front")
        {
            if (s.empty())
                cout << "-1\n";
            else
            {
                cout << s.front() << "\n";
                s.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (s.empty())
                cout << "-1\n";
            else
            {
                cout << s.back() << "\n";
                s.pop_back();
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