#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool p[1001];
int N, K;
int dcount, curidx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>K;
    memset(p, 1, sizeof(p));
    dcount = 0;
    curidx = 0;
    cout<<"<";
    while (dcount != N)
    {
        for(int i=0; i<K; i++)
        {
            // move to next
            curidx++;
            if (curidx > N)
                curidx -= N;
            
            // if next slot is already deleted
            if (!p[curidx])
                i--;
        }
        cout<<curidx;
        if (dcount != N-1)
            cout<<", ";
        dcount++;
        p[curidx] = 0;
    }
    cout<<">\n";
}