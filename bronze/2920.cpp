#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool as, des;
    as = des = true;
    int cur, before;
    cin>>before;
    for(int i=0; i<7; i++)
    {
        cin>>cur;
        if (cur > before)
            des = false;
        else if (cur < before)
            as = false;
        before = cur;
    }
    if (as)
        cout<<"ascending\n";
    else if (des)
        cout<<"descending\n";
    else
        cout<<"mixed\n";
}