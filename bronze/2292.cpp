#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;

    int from = 0;
    int to = 1;
    int i = 0;
    while (1)
    {
        i++;
        if (N >= from && N <= to)
        {
            cout<<i<<endl;
            break;
        }

        from = to + 1;
        to = 6*i + to;
    }
}