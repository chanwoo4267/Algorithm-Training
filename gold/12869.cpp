#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, scv[3], ans = 9999999;
const int D[6][3] = { {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };
bool visit[61][61][61][20];

struct SCV_s 
{ 
	int a, b, c, cnt;
	SCV_s() 
    {
        a = -1;
        b = -1;
        c = -1;
        cnt = -1;
    }
	SCV_s(int aa, int bb, int cc, int xx)
    {
        a = aa;
        b = bb;
        c = cc;
        cnt = xx;
    }
};

int main() 
{
	cin>>N;
	for (int i = 0; i < N; ++i) 
        cin>>scv[i];
	
	queue<SCV_s> q;
	q.push(SCV_s(scv[0], scv[1], scv[2], 0));
	visit[scv[0]][scv[1]][scv[2]][0] = 1;

	while (!q.empty()) 
    {
		SCV_s now = q.front();
		q.pop();
		if (!now.a && !now.b && !now.c) 
            ans = min(ans, now.cnt);

		for (int i = 0; i < 6; ++i) 
        {
			int a = now.a - D[i][0], b = now.b - D[i][1], c = now.c - D[i][2], x = now.cnt + 1;
			a < 0 ? a = 0 : a = a;
            b < 0 ? b = 0 : b = b;
            c < 0 ? c = 0 : c = c;
			if (!visit[a][b][c][x]) {
				visit[a][b][c][x] = 1;
				q.push(SCV_s(a, b, c, x));
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}