#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int apt[15][15];
int N, K, test_case;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>test_case;

    for(int i=0; i<15; i++) // floor
    {
        for (int j = 1; j < 15; j++) // 호, 0호없음
        {
            if (i == 0)
                apt[i][j] = j;
            else
            {
                for(int p=1; p<=j; p++)
                    apt[i][j] += apt[i-1][p];
            }
        }    
    }

    for(int t=0; t<test_case; t++)
    {
        cin>>K>>N; // 층, 호
        cout<<apt[K][N]<<"\n";
    }
}