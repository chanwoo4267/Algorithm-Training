#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> s;
int N, temp, res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        if (temp == 0)
            s.pop();
        else
            s.push(temp);
    }

    res = 0;
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    cout<<res<<"\n";
}