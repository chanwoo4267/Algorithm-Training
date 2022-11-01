#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visited[1001];

void dfs(int index)
{
    vector<int> next;

    if (!visited[index])
    {
        visited[index] = true;
        cout<<index<<" ";
        for(int i=0; i<graph[index].size(); i++)
            next.push_back(graph[index][i]);
        
        sort(next.begin(), next.end());

        for(int i=0; i<next.size(); i++)
            dfs(next[i]);
    }
}

void bfs(int index)
{
    queue<int> q;
    vector<int> next;
    int cur;
    q.push(index);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        if (!visited[cur])
        {
            visited[cur] = true;
            cout<<cur<<" ";
            for(int i=0; i<graph[cur].size(); i++)
                next.push_back(graph[cur][i]);
            
            sort(next.begin(), next.end());

            for(int i=0; i<next.size(); i++)
                q.push(next[i]);

            next.clear();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M>>V;
    int temp1, temp2;
    for(int i=0; i<M; i++)
    {
        cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    for(int i=0; i<N; i++)
        sort(graph[i].begin(), graph[i].end());

    memset(visited, 0, sizeof(visited));
    dfs(V);

    cout<<"\n";

    memset(visited, 0, sizeof(visited));
    bfs(V);
}