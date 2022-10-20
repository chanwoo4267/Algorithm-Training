#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define WHITE 0
#define BLACK 1

int min_change = 65;
bool board[50][50];
int r,c;

void test_board(int row, int col)
{
    int res = 0;
    bool flag = board[row][col];

    for(int i=row; i<row + 8; i++)
    {
        for(int j=col; j<col + 8; j++)
        {
            if (board[i][j] != flag)
                res++;
            flag = !flag;
        }
        flag = !flag;
    }

    min_change = min(min_change, res);

    res = 0;
    flag = !board[row][col];
    for(int i=row; i<row + 8; i++)
    {
        for(int j=col; j<col + 8; j++)
        {
            if (board[i][j] != flag)
                res++;
            flag = !flag;
        }
        flag = !flag;
    }

    min_change = min(min_change, res);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            if (str[j] == 'W')
                board[i][j] = WHITE;
            else
                board[i][j] = BLACK;
        }
    }
        
    for(int i=0; i<r - 7; i++)
        for(int j=0; j<c - 7; j++)
            test_board(i, j);
        
    cout<<min_change<<"\n";
}