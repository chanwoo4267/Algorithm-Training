#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// stack의 제일 위에 있는게 가장 큰 정수
// 따라서 입력받은 수열과 가장 위 원소를 비교해서 작다면 그때까지 push한 뒤 pop 1번
// 크다면 그 수가 나올때까지 pop
// 이때 이전까지 넣은 수를 저장하면서 이미 pop해버린 수를 나중에 요구한다면? NO 출력

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cur_input = 1;
    int N, cur;
    stack<int> stk;
    vector<bool> printer;
    stk.push(0); // empty operation 방지

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>cur;
        if (stk.top() == cur)
        {
            stk.pop();
            printer.push_back(0);
        }
        else if (stk.top() < cur)
        {
            if (cur_input > cur)
            {
                cout<<"NO\n";
                return 0;
            }
            while (cur_input <= cur)
            {
                stk.push(cur_input);
                printer.push_back(1);
                cur_input++;
            }
            stk.pop();
            printer.push_back(0);
        }
        else
        {
            while (!stk.empty() && stk.top() != cur)
            {
                stk.pop();
                printer.push_back(0);
            }
            if (stk.empty())
            {
                cout<<"NO\n";
                return 0;
            }
            stk.pop();
            printer.push_back(0);
        }
    }

    for(int i=0; i<printer.size(); i++)
    {
        if (printer[i] == 1)
            cout<<"+\n";
        else
            cout<<"-\n";
    }
}