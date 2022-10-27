#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > v;
int N;

int get_rank(int x, int y)
{
    int rank = 1;
    for(int i=0; i<v.size(); i++)
    {
        if (x < v[i].first && y < v[i].second)
            rank++;
    }
    return rank;
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

    for(int i=0; i<N; i++)
    {
        int r = get_rank(v[i].first, v[i].second);
        cout<<r<<" ";
    }
}