#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> l;

bool bs(int n)
{
    int start = 0;
    int end = l.size() - 1;
    int mid = (start + end) / 2;

    while(end-start >= 0)
    {
        if (l[mid] == n)
            return true;
        else if (l[mid] <= n)
            start = mid + 1;
        else
            end = mid - 1;
        mid = (start + end) / 2;
 	}
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,M,t;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>t;
        l.push_back(t);
    }
    sort(l.begin(), l.end());

    cin>>M;
    for(int i=0; i<M; i++)
    {
        cin>>t;
        if (!bs(t))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
}