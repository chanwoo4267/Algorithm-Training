#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool check;

void recur(int level, int row, int column, int count)
{
    if (check)
        return;

    if (level == 0)
    {
        cout<<count<<endl;
        check = true;
        return;
    }

    if (row < pow(2, level - 1) && column < pow(2, level - 1))
        recur(level - 1, row, column, count);
    else if (row < pow(2, level - 1) && column >= pow(2, level - 1))
        recur(level - 1, row, column - pow(2, level - 1), count + pow(4, level - 1));
    else if (row >= pow(2, level - 1) && column < pow(2, level - 1))
        recur(level - 1, row - pow(2, level - 1), column, count + pow(4, level - 1) * 2);
    else
        recur(level - 1, row - pow(2, level - 1), column - pow(2, level - 1), count + pow(4, level - 1) * 3);
}

int main()
{
    int N, R, C;
    cin>>N>>R>>C;
    check = false;
    recur(N, R, C, 0);
}