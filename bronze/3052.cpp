#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    vector<int> v;
    for(int i=0; i<10; i++)
    {
        cin>>t;
        if (!count(v.begin(), v.end(), t % 42))
            v.push_back(t % 42);
    }
    cout<<v.size()<<"\n";
}