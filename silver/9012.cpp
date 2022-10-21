#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, idx, cnt;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>str;
        cnt = 0;
        for(idx=0; idx<str.length(); idx++)
        {
            //cout<<"index, cnt | "<<idx<<" "<<cnt<<"| current char : "<<str[idx]<<"\n";
            if (str[idx] == '(')
                cnt++;
            else
                cnt--;
            
            if (cnt < 0)
                break;
        }
        if (cnt == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}