#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > v;
int N;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    int x,y;
    for(int i=0; i<N; i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<N; i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
}