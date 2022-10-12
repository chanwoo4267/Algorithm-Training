#include <iostream>
#include <cstring>
using namespace std;

bool prime[1000001];
int N;
bool flag;

void init()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;

    for(int i=2; i<=1000000; i++)
    {
        if (prime[i] == 0)
            continue;
        for(int j=2*i; j<=1000000; j+=i)
            prime[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    while(1)
    {
        cin>>N;
        if (N == 0)
            break;
    
        flag = false;    
        int i;
        for(i=2; i<=N / 2; i++)
        {
            if (prime[i] != 0 && prime[N - i] != 0)
            {
                cout << N << " = " <<  i << " + " << N - i << "\n";
                flag = true;
                break;
            }
        }

        if (!flag)
            cout<<"Goldbach's conjecture is wrong.\n";
    }
    return 0;
}