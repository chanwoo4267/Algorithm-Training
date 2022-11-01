#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, r, c, vnum, x, y;
bool board[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int counter;

void dfs(int row, int col)
{
    if (row < 0 || row >= r || col < 0 || col >= c)
        return;
    if (board[row][col] == 0)
        return;
    
    board[row][col] = 0;

    for(int i=0; i<4; i++)
        dfs(row + dy[i], col + dx[i]);
}

void checker()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if (board[i][j] == 0)
                continue;
            else
            {
                counter++;
                dfs(i, j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>T;
    for(int i=0; i<T; i++)
    {
        memset(board, 0, sizeof(board));
        cin>>c>>r>>vnum;
        for(int j=0; j<vnum; j++)
        {
            cin>>x>>y;
            board[y][x] = true;
        }
        counter = 0;
        checker();
        cout<<counter<<"\n";
    }
}