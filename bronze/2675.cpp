#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, itr;
    string str;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>itr>>str;
        for(int j=0; j<str.length(); j++)
        {
            for(int k=0; k<itr; k++)
                cout<<str[j];
        }
        cout<<"\n";
    }
}