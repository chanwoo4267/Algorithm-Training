#include <iostream>
#include <string.h>
 
using namespace std;
 
int N;
int map[3000][3000];
int counter[3];
 
// check whether all digits are same
bool check(int x, int y, int n) 
{
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (map[x + i][y + j] != map[x][y]) 
                return false;
 
    return true;
}
 
void solve(int x, int y, int n) 
{
    if (check(x, y, n)) 
    {
        int index = map[x][y];
        counter[index + 1]++;
        return;
    }

    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            solve(x + (n/3) * i, y + (n/3) * j, (n/3));
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> map[i][j];

    solve(0, 0, N);
 
    for (int i = 0; i < 3; i++)
        cout << counter[i] << "\n";
 
    return 0;
}
