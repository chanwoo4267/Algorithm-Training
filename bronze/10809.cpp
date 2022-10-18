#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int alp[26];
    memset(alp, -1, sizeof(alp));
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++)
    {
        if (alp[str[i] - 'a'] == -1)
            alp[str[i] - 'a'] = i;
    }

    for(int i=0; i<26; i++)
        cout<<alp[i]<<" ";
}