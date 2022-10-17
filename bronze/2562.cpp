#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxr = 0;
    int maxi = 0;
    int temp;
    for(int i=1; i<10; i++)
    {
        cin>>temp;
        if (temp > maxr)
        {
            maxr = temp;
            maxi = i;
        }
    }
    cout<<maxr<<"\n"<<maxi<<"\n";
}