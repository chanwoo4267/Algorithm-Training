#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long result = 0;
    int N;
    string str;
    cin>>N>>str;
    for(int i=0; i<N; i++)
    {
        //pow
        unsigned long long temp = 1;
        int t = i;
        while (t > 0)
        {
            temp *= 31;
            t--;
            if (temp > 1234567891)
                temp = temp % 1234567891;
        }
        result += (str[i] - 'a' + 1) * temp;
        if (result > 1234567891)
            result = result % 1234567891;
    }
    cout<<result<<"\n";
}