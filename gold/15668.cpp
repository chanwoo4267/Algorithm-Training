#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// variables
int N;
int res;
int check[10];

int main()
{
    cin>>N;
    for(int i=1; i<min(N, 98765); i++)
    {
        memset(check, 0, sizeof(check));
        int a = i;
        int b = N - i;
        bool flag = true;
        while (a && flag)
        {
            check[a%10]++;
            if (check[a%10] > 1)
                flag = false;
            a /= 10;
        }
        while (b)
        {
            check[b%10]++;
            if (check[b%10] > 1)
                flag = false;
            b /= 10;
        }
        if (flag)
        {
            cout<<i<<" + "<<N-i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}