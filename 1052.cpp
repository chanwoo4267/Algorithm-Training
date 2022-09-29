#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 10000000
#define MAX_K 1000

bool a[30];
int cnt;

void arr_p()
{
    cout << "array print" << endl;
    for (int i = 0; i < 30; i++)
        if (a[i] == 1)
            cout << pow(2, i) << endl;
    cout << endl;
}

int main()
{
    long long N; 
    int K;
    for (int i = 0; i < 30; i++)
        a[i] = 0;
    cnt = 0;
    scanf("%lld %d", &N, &K);
    
    if (K <= 0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    long long p = pow(2, 29);
    for (int i = 29; i >= 0; i--)
    {
        p = pow(2, i);
        if (N >= p)
        {
            a[i] = 1;
            cnt++;
            N -= p;
        }
    }

    if (cnt <= K)
    {
        cout << "0" << endl;
        return 0;
    }

    int need = 0;

    while (cnt > K)
    {
        int start;
        int target;

        for (start = 0; start < 30; start++)
            if (a[start] == 1)
                break;
        for (target = start + 1; target < 30; target++)
            if (a[target] == 1)
                break;
        need += pow(2, target) - pow(2, start);
        a[start] = 0;
        a[target] = 0;
        while (target < 29)
        {
            target++;
            if (a[target] == 0)
            {
                a[target] = 1;
                cnt--;
                break;
            }
            else
            {
                a[target] = 0;
                cnt--;
            }
        }
    }

    cout << need << endl;
}