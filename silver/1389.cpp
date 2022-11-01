#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int Map[101][101];
int N, M;

void floid()
{
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
            {
                if (i == j) continue;
                else if (Map[i][k] != 0 && Map[k][j] != 0)
                {
                    if (Map[i][j] == 0)
                        Map[i][j] = Map[i][k] + Map[k][j];
                    else
                        Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
                }
            }
}

int getresult()
{
    int result = 2147483647;
    int p = 1;
    for(int i=1; i<=N; i++)
    {
        int temp = 0;
        for(int j=1; j<=N; j++)
        {
            temp += Map[i][j];
        }

        if (result > temp)
        {
            result = temp;
            p = i;
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;
    int temp1, temp2;

    for(int i=0; i<M; i++)
    {
        cin>>temp1>>temp2;
        Map[temp1][temp2] = 1;
        Map[temp2][temp1] = 1;
    }

    floid();
    cout<<getresult()<<"\n";
}