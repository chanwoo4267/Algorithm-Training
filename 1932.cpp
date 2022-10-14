#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[501]; // n : 1~500
int t[501];
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(memo, 0, sizeof(memo));
    cin>>N;
    for(int i=0; i<N; i++) // line number && max nums
    {
        int temp;
        for(int j=0; j<i+1; j++) // index of nums
        {
            cin>>temp;
            if (j == 0)
                t[j] = temp + memo[j];
            else if (j == i)
                t[j] = temp + memo[j - 1];
            else
                t[j] = max(temp + memo[j - 1], temp + memo[j]);
        }

        for(int j=0; j<i+1; j++) // renew memoziation array
            memo[j] = t[j];
    }

    int maxx = 0;
    for(int i=0; i<N; i++)
        if (memo[i] > maxx)
            maxx = memo[i];
    cout<<maxx<<"\n";
}