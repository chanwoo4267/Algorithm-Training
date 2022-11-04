#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, two, five;

void divideby(int num)
{
    while (num % 2 == 0)
    {
        num /= 2;
        two++;
    }
    while (num % 5 == 0)
    {
        num /= 5;
        five++;
    }
}

void solve()
{
    two = five = 0;

    while (N > 1)
    {
        divideby(N);
        N--;
    }

    cout<<min(two, five)<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    solve();
}