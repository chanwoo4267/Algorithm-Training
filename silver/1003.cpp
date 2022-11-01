#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, t;

typedef struct {
    int zero;
    int one;
} Node;

Node fb_count[41];

Node fibo(int n)
{
    if (n == 0)
    {
        fb_count[0].zero = 1;
        fb_count[0].one = 0;
        return fb_count[0];
    }
    else if (n == 1)
    {
        fb_count[1].zero = 0;
        fb_count[1].one = 1;
        return fb_count[1];
    }
    else
    {
        if (fb_count[n].zero != 0 && fb_count[n].one != 0)
        {
            return fb_count[n];
        }
        else
        {
            fb_count[n].zero = fibo(n-1).zero + fibo(n-2).zero;
            fb_count[n].one = fibo(n-1).one + fibo(n-2).one;
            return fb_count[n];
        }
    }  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //init
    for(int i=0; i<41; i++)
    {
        fb_count[i].zero = fb_count[i].one = 0;
    }

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>t;
        fibo(t);
        cout<<fb_count[t].zero<<" "<<fb_count[t].one<<"\n";
    }
}