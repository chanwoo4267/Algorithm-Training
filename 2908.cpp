#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int newa, newb;
    cin>>a>>b;
    newa = newb = 0;

    while (a)
    {
        newa = (newa * 10) + (a % 10);
        a /= 10;
    }
    while (b)
    {
        newb = (newb * 10) + (b % 10);
        b /= 10;
    }

    newa > newb ? cout<<newa : cout<<newb;
    cout<<"\n";
}