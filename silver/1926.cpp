#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define EMPTY 0
#define PAINT 1
#define CHECKED 2

int board[500][500];
int r,c;
vector<int> picsize;
int totalpic;

void paint();
int dfs(int row, int col);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    totalpic = 0;

    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>board[i][j];
    
    paint();
    sort(picsize.begin(), picsize.end());
    cout<<totalpic<<"\n";
    if (picsize.size() != 0)
        cout<<picsize[picsize.size() - 1]<<"\n";
    else
        cout<<"0"<<"\n";
}

void paint()
{
    int currentpaint;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            currentpaint = dfs(i, j);
            if (currentpaint)
            {
                totalpic++;
                picsize.push_back(currentpaint);
            }
        }
    }
}

int dfs(int row, int col)
{
    int res = 0;

    if (row >= 0 && row < r && col >= 0 && col < c && board[row][col] == PAINT)
    {
        board[row][col] = CHECKED;
        res++;
        res += dfs(row - 1, col);
        res += dfs(row + 1, col);
        res += dfs(row, col - 1);
        res += dfs(row, col + 1);
    }

    return res;
}