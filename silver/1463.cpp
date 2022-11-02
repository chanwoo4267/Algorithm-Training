#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1000001];

void dpf(int N)
{
    dp[1] = 0;
    for(int i=2; i<=N; i++)
    {
        int temp = dp[i-1] + 1;
        if (i % 3 == 0)
            temp = min(temp, dp[i / 3] + 1);
        if (i % 2 == 0)
            temp = min(temp, dp[i / 2] + 1);
        dp[i] = temp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    dpf(N);
    cout<<dp[N]<<"\n";
}