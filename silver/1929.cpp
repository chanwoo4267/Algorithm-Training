#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool prime[1000001];
int from, to;

void solve()
{
    prime[0] = 0;
    prime[1] = 0;

    for(int i=2; i<=to; i++)
    {
        if (!prime[i]) continue;
        
        for(int j=2*i; j<=to; j+=i)
            prime[j] = 0;
    }

    //print
    for(int i=from; i<=to; i++)
        if (prime[i] == 1)
            cout<<i<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(prime, 1, sizeof(prime));
    cin>>from>>to;
    solve();
}