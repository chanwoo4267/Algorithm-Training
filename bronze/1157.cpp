#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int cnt[26];

int main()
{
    memset(cnt, 0, sizeof(cnt));
    string str;
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            cnt[str[i] - 'a']++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            cnt[str[i] - 'A']++;
    }

    int maxcnt = 0;
    char maxchar = '?';
    for(int i=0; i<26; i++)
    {
        if (maxcnt < cnt[i])
        {
            maxcnt = cnt[i];
            maxchar = i + 'A';
        }
        else if (maxcnt == cnt[i] && maxcnt != 0)
        {
            maxchar = '?';
        }
    }
    cout<<maxchar<<"\n";
}