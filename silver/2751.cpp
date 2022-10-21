#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    int temp;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<N; i++)
        cout<<v[i]<<"\n";
}