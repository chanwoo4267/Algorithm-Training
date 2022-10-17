#include <iostream>
using namespace std;

int map[100][100] = {0, };
int r1, r2, c1, c2;
int last_spaces;

void check_range(int curx, int cury, int cur)
{
    if (cury >= r1 && cury <= r2 && curx >= c1 && curx <= c2)
    {
        map[cury - r1][curx - c1] = cur;
        last_spaces = to_string(cur).length();
    }
}

int main()
{
    cin>>r1>>c1>>r2>>c2;

    int ix, iy, cur;
    ix = 0; iy = 0; cur = 1;

    for(int circulation = 0; circulation < 5001; circulation++)
    {
        for(int mv=0; mv < circulation * 2 + 1; mv++) // right
        {
            check_range(ix, iy, cur);
            ix++;
            cur++;
        }
        for(int mv=0; mv < circulation * 2 + 1; mv++) // up
        {
            check_range(ix, iy, cur);
            iy--;
            cur++;
        }
        for(int mv=0; mv < circulation * 2 + 2; mv++)
        {
            check_range(ix, iy, cur);
            ix--;
            cur++;
        }
        for(int mv=0; mv < circulation * 2 + 2; mv++) // up
        {
            check_range(ix, iy, cur);
            iy++;
            cur++;
        }
    }

    for(int i=0; i<=r2 - r1; i++)
    {
        for(int j=0; j<=c2 - c1; j++)
        {
            int sp = last_spaces - to_string(map[i][j]).length();
            for(int i=0; i<sp; i++)
                cout<<" ";
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}