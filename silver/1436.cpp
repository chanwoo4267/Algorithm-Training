#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_666(long cur)
{
    int c = 0;
    int max_c = 0;
    while (cur)
    {
        if (cur % 10 == 6)
        {
            c = 0;
            while (cur)
            {
                if (cur % 10 == 6)
                    c++;
                else
                    break;
                cur /= 10;
            }
            max_c = max(max_c, c);
        }
        cur /= 10;
    }

    bool return_value;
    max_c >= 3 ? return_value = true : return_value = false;
    return return_value;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, count = 0;
    long cur = 1;
    cin>>N;
    while (count != N)
    {
        if (check_666(cur))
            count++;
        cur++;
    }
    cout<<cur-1<<"\n";
}