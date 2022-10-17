#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxr = -2147483648;
    int minr = 2147483647;
    int n, temp;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        if (temp > maxr)
            maxr = temp;
        if (temp < minr)
            minr = temp;
    }
    cout<<minr<<" "<<maxr<<"\n";
}