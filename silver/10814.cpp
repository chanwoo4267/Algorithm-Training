#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, string> > v;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, d;
    string str;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>d>>str;
        v.push_back(make_pair(d, str));
    }

    stable_sort(v.begin(), v.end(),compare);

    for(int i=0; i<n; i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
}