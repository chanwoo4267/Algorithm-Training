#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int fac(int n)
{
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>K;
    unsigned long long result = fac(N);
    result = result / fac(K);
    result = result / fac(N-K);
    cout<<result<<"\n";
}