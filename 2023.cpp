#include <iostream>
#include <cstring>
using namespace std;

int N;

bool primetest(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

void dfs(int head, int level)
{
    if (level == 0)
        cout << head << "\n";
    else
    {
        for (int i = 1; i < 10; i += 2)
        {
            if (primetest(head * 10 + i))
                dfs(head * 10 + i, level - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    dfs(2, N - 1);
    dfs(3, N - 1);
    dfs(5, N - 1);
    dfs(7, N - 1);
}