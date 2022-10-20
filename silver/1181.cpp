#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

struct Compare
{
    bool operator() (const string &x, const string &y) const
    {
        if (x.length() == y.length())
            return x < y;
        else
            return x.length() < y.length();
    }
};

set<string, Compare> dict;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    string str;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>str;
        dict.insert(str);
    }

    for(auto it = dict.begin(); it != dict.end(); it++)
        cout<<*it<<"\n";
}