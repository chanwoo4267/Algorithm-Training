#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

class Mapp
{
    public:
        bool map[4][4];
        long hash;
        int step;

        Mapp(bool m[4][4], int s)
        {
            hash = 0;
            step = 0;
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++)
                {
                    map[i][j] = m[i][j];
                    if (m[i][j]) 
						hash += (1 << (i * 4 + j));
                }
            
            step = s;
        }

        void swap(int x, int y, int nx, int ny)
        {
            bool temp = map[x][y];
			map[x][y] = map[nx][ny];
			map[nx][ny] = temp;
        }

        long gethash()
        {
            return hash;
        }
};

bool board[4][4];
bool target[4][4];
Mapp *R;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<Mapp> q;
unordered_set<long> visit;

void input();
int bfs();

int main()
{
    input();
    R = new Mapp(target, 0);
    q.push(Mapp(board, 0));
    visit.insert(q.front().gethash());

    cout<<bfs()<<endl;
}

void input()
{
    string s;
    for(int i=0; i<4; i++)
    {
        cin>>s;
        for(int j=0; j<4; j++)
        {
            if (s[j] == 'P')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }

    for(int i=0; i<4; i++)
    {
        cin>>s;
        for(int j=0; j<4; j++)
        {
            if (s[j] == 'P')
                target[i][j] = 1;
            else
                target[i][j] = 0;
        }
    }
}

int bfs()
{
    while (!q.empty())
    {
        Mapp now = q.front();
        q.pop();

        if (now.gethash() == R->gethash())
            return now.step;

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
                    {
                        now.swap(x, y, nx, ny);
                        Mapp next = Mapp(now.map, now.step + 1);
                        auto iter = visit.find(next.gethash());
                        if (iter == visit.end())
                        {
                            visit.insert(next.gethash());
                            q.push(next);
                        }
                        now.swap(x, y, nx, ny);
                    }
                }
            }
        }
    }
    return -1;
}