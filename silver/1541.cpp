#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

string str;
int start, len, result;
bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>str;

    start = len = result = flag = 0;
    for(int i=0; i<str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            // make substring
            string sub(str.c_str() + start, len);

            if (!flag)
                result += atoi(sub.c_str());
            else
                result -= atoi(sub.c_str());
                
            // once minus occured, next results always minus
            if (str[i] == '-')
                flag = 1;
            
            start = i + 1;
            len = 0;
        }
        else
            len++;
    }

    string sub(str.c_str() + start, len);
    if (!flag)
        result += atoi(sub.c_str());
    else
        result -= atoi(sub.c_str());

    cout<<result<<"\n";
    
}