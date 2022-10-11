#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector< pair<string, string> > v;
int res = 0;

int getres()
{
    if (v.empty())
        return 1;
    string from = v[0].first;
    string to = v[0].second;

    while (1)
    {
        next:
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first.compare(to) == 0) // find manitto
            {
                from = v[i].first;
                to = v[i].second;
                v.erase(v.begin() + i);
                goto next;
            }
        }
        break;
    }
    res++;
    return 0;
}

int main()
{
    int t = 1;
    int n;
    string s1, s2;

    while (1)
    {
        cin >> n;
        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            v.push_back(make_pair(s1, s2));
        }

        while (1)
        {
            if (getres())
                break;
        }
        cout << t++ << " " << res << endl;
        v.clear();
        res = 0;
    }
}