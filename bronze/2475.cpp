#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int result = 0;
    int temp;
    for(int i=0; i<5; i++)
    {
        cin>>temp;
        result += pow(temp, 2);
    }
    cout<<result % 10<<endl;
}