#include <iostream>
#include <queue>
using namespace std;

int counter, test_case, n, m, priority, index, value;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> test_case;
    for (int i = 0; i < test_case; ++i) 
    {
        counter = 0;
        cin >> n >> m;
        queue< pair<int, int> > q;
        priority_queue<int> pq;

        for (int j = 0; j < n; j++) 
        {
            cin >> priority;
            q.push(make_pair(j, priority));
            pq.push(priority);
        }

        while (!q.empty()) 
        {
            index = q.front().first;
            value = q.front().second;

            q.pop();
            if (pq.top() == value) 
            {
                pq.pop();
                counter++;
                if (index == m) 
                {
                    cout << counter << endl;
                    break;
                }
            }
            else q.push(make_pair(index,value));
        }
    }
}