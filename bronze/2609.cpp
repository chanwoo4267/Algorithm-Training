#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getgcd(long long a, long long b)
{
    long long temp = 0;
    while (b > 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long long getlcm(long long a, long long b)
{
    return a * b / getgcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    cin>>a>>b;
    cout<<getgcd(a,b)<<"\n"<<getlcm(a,b)<<"\n";
}