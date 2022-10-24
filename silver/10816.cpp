#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, d;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());

    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>d;
        auto ub = upper_bound(v.begin(), v.end(), d);
        auto lb = lower_bound(v.begin(), v.end(), d);
        cout<<ub - lb<<" ";
    }
    cout<<"\n";
}