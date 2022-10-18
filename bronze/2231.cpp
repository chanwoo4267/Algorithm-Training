#include <iostream>
using namespace std;

int calc(int N)
{
    int result = 0;
    while (N)
    {
        result += N % 10;
        N /= 10;
    }
    return result;
}

int main()
{
    int N;
    cin>>N;

    for(int i = 1; i < N; i++)
    {
        if (i + calc(i) == N)
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"0\n";
}