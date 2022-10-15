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
int min_result;

void calc(int cctv_index);
void check_map();
void paint_line(int cctv_row, int cctv_col, int dir);
int **make_backup();
void restore_map(int **backup);
void paint(int cctv_row, int cctv_col, int dir, int cctv_num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cctv_num = 0;
    cin>>r>>c;
    min_result = r*c;
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

    calc(0);
    cout<<min_result<<"\n";
}

void calc(int cctv_index)
{
    if (cctv_index == cctv_num)
    {
       check_map();
       return;
    }

    int **map_backup = make_backup();

    int cctv_row = cctv[cctv_index].first;
    int cctv_col = cctv[cctv_index].second;

    paint(cctv_row, cctv_col, LEFT, map[cctv_row][cctv_col]);
    calc(cctv_index + 1);
    restore_map(map_backup);

    paint(cctv_row, cctv_col, UP, map[cctv_row][cctv_col]);
    calc(cctv_index + 1);
    restore_map(map_backup);

    paint(cctv_row, cctv_col, RIGHT, map[cctv_row][cctv_col]);
    calc(cctv_index + 1);
    restore_map(map_backup);

    paint(cctv_row, cctv_col, DOWN, map[cctv_row][cctv_col]);
    calc(cctv_index + 1);
    restore_map(map_backup);
}

void paint(int cctv_row, int cctv_col, int dir, int cctv_num)
{
    if (cctv_num == 1)
        paint_line(cctv_row, cctv_col, dir);
    else if (cctv_num == 2)
    {
        paint_line(cctv_row, cctv_col, dir);
        dir + 2 > DOWN ? dir -= 2 : dir += 2;
        paint_line(cctv_row, cctv_col, dir);
    }
    else if (cctv_num == 3)
    {
        paint_line(cctv_row, cctv_col, dir);
        dir + 1 > DOWN ? dir -= 3 : dir += 1;
        paint_line(cctv_row, cctv_col, dir);
    }
    else if (cctv_num == 4)
    {
        paint_line(cctv_row, cctv_col, dir);
        dir + 1 > DOWN ? dir -= 3 : dir += 1;
        paint_line(cctv_row, cctv_col, dir);
        dir + 1 > DOWN ? dir -= 3 : dir += 1;
        paint_line(cctv_row, cctv_col, dir);
    }
    else if (cctv_num == 5)
    {
        paint_line(cctv_row, cctv_col, LEFT);
        paint_line(cctv_row, cctv_col, UP);
        paint_line(cctv_row, cctv_col, RIGHT);
        paint_line(cctv_row, cctv_col, DOWN);
    }
}

int **make_backup()
{
    int **arr = new int*[8];
    for(int i=0; i<8; i++)
        arr[i] = new int[8];

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            arr[i][j] = map[i][j];

    return arr;
}

void restore_map(int **backup)
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            map[i][j] = backup[i][j];
}

void check_map()
{
    int result = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if (map[i][j] == 0)
                result++;

    if (result < min_result)
        min_result = result;
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
            else if (map[cctv_row][tc] == 6)
                break;
            tc--;
        }
    }
    else if (dir == RIGHT)
    {
        int tc = cctv_col + 1;
        while (tc < c)
        {
            if (map[cctv_row][tc] == 0)
                map[cctv_row][tc] = OBSERVED;
            else if (map[cctv_row][tc] == 6)
                break;
            tc++;
        }
    }
    else if (dir == UP)
    {
        int tr = cctv_row - 1;
        while (tr >= 0)
        {
            if (map[tr][cctv_col] == 0)
                map[tr][cctv_col] = OBSERVED;
            else if (map[tr][cctv_col] == 6)
                break;
            tr--;
        }
    }
    else if (dir == DOWN)
    {
        int tr = cctv_row + 1;
        while (tr < r)
        {
            if (map[tr][cctv_col] == 0)
                map[tr][cctv_col] = OBSERVED;
            else if (map[tr][cctv_col] == 6)
                break;
            tr++;
        }
    }
}