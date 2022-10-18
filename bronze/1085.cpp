#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    cout<<min(abs(x-w), min(abs(y-h), min(abs(x), abs(y))));
}