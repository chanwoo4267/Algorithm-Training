#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    int i = 2;
    while (i <= sqrt(n))
    {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, t, cnt = 0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>t;
        if (isprime(t))
            cnt++;
    }
    cout<<cnt<<"\n";
}