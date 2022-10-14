#include <iostream>
#include <vector>
using namespace std;

#define OBSERVED -1
#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4

int r,c;
int map[8][8]; // width, height = 1~8;
int map_backup[8][8];
vector< pair<int, int> > cctv;
int cctv_num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cctv_num = 0;
    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
            {
                cctv.push_back(make_pair(i, j));
                cctv_num++;
            }
        }


}

void calc(int cctv_index)
{
    if (cctv_index == cctv_num)
    {
       // check_map()
    }

    int cctv_row = cctv[i].first;
    int cctv_col = cctv[i].second;

}

void paint_line(int cctv_row, int cctv_col, int dir)
{
    if (dir == LEFT)
    {
        int tc = cctv_col - 1;
        while (tc >= 0)
        {
            if (map[cctv_row][tc] == 0)
                map[cctv_row][tc] = OBSERVED;
            tc--;
        }
    }
    else if (dir == RIGHT)
    {
        int tc = cctv_col + 1;
        while (tc <= 7)
        {
            if (map[cctv_row][tc] == 0)
                map[cctv_row][tc] = OBSERVED;
            tc++;
        }
    }
    else if (dir == UP)
    {
        
    }
}