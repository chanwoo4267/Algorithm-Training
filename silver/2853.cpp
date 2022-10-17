#include <iostream>
using namespace std;

int main()
{
    int N;
    int arr[5000] = {0};
    int res = 0;

    cin>>N;
    for(int days=0; days < N; days++)
        cin>>arr[days];
    for(int i=1; i<N; i++)
    {
        if (arr[i] == 0)
            continue;

        int dist = arr[i] - 1;
        bool flag = false;
        for(int j=1; j<N; j++)
        {
            if (arr[j] == 0)
                continue;

            if ((arr[j] - 1) % dist == 0)
            {
                arr[j] = 0;
                flag = true;
            }
        }
        if (flag)
            res++;
    }
    cout<<res<<endl;
}