#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    while (!cin.eof())
    {
        cout<<a+b<<endl;
        cin>>a>>b;
    }
}