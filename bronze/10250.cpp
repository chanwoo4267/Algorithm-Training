#include <iostream>
using namespace std;

int main()
{
    int test_case, h, w, n;
    cin>>test_case;
    for(int i=0; i<test_case; i++)
    {
        int result = 1;
        cin>>h>>w>>n;
        while (!(n >= 1 && n <= h))
        {
            result += 1;
            n -= h;
        }
        result += 100 * n;
        cout<<result<<"\n";
    }
}