#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define LEFT 1
#define RIGHT 3
#define UP 2
#define DOWN 4

typedef struct _robot
{
    int dir;
    int x;
    int y;
} robot;

robot robots[101];
int board[101][101]; // x,y는 1~100

void rotate_robot(int robot_index, char direction)
{
    if (direction == 'L')
    {
        if (robots[robot_index].dir == LEFT)
            robots[robot_index].dir = DOWN;
        else
            robots[robot_index].dir -= 1;
    }
    else
    {
        if (robots[robot_index].dir == DOWN)
            robots[robot_index].dir = LEFT;
        else
            robots[robot_index].dir += 1;
    }
}

int main()
{
    int X, Y, N, M;
    memset(board, 0, sizeof(board));
    cin >> X >> Y;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> robots[i].x >> robots[i].y >> c; // robot index는 1~100
        if (c == 'E')
            robots[i].dir = RIGHT;
        else if (c == 'W')
            robots[i].dir = LEFT;
        else if (c == 'N')
            robots[i].dir = UP;
        else
            robots[i].dir = DOWN;
        board[robots[i].x][robots[i].y] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int robot_index, distance, j;
        char direction;
        cin >> robot_index >> direction >> distance;

        if (direction == 'L' || direction == 'R')
            while (distance != 0)
            {
                rotate_robot(robot_index, direction);
                distance--;
            }
        else
        {
            if (robots[robot_index].dir == LEFT)
            {
                for (j = 0; j < distance; j++)
                {
                    if (robots[robot_index].x - 1 <= 0) // x,y 범위는 1~100. 즉 0이하면 벽에 부딪힘
                    {
                        cout << "Robot " << robot_index << " crashes into the wall" << endl;
                        return 0;
                    }
                    else if (board[robots[robot_index].x - 1][robots[robot_index].y] != 0) // 이동할 보드 위치가 0이 아니면 다른로봇이 존재.
                    {
                        cout << "Robot " << robot_index << " crashes into robot " << board[robots[robot_index].x - 1][robots[robot_index].y] << endl;
                        return 0;
                    }
                    else
                    {
                        board[robots[robot_index].x - 1][robots[robot_index].y] = robot_index;
                        board[robots[robot_index].x][robots[robot_index].y] = 0;
                        robots[robot_index].x -= 1;
                    }
                }
            }
            if (robots[robot_index].dir == RIGHT)
            {
                for (j = 0; j < distance; j++)
                {
                    if (robots[robot_index].x + 1 > X) // x,y 범위는 1~100. 즉 0이하면 벽에 부딪힘
                    {
                        cout << "Robot " << robot_index << " crashes into the wall" << endl;
                        return 0;
                    }
                    else if (board[robots[robot_index].x + 1][robots[robot_index].y] != 0) // 이동할 보드 위치가 0이 아니면 다른로봇이 존재.
                    {
                        cout << "Robot " << robot_index << " crashes into robot " << board[robots[robot_index].x + 1][robots[robot_index].y] << endl;
                        return 0;
                    }
                    else
                    {
                        board[robots[robot_index].x + 1][robots[robot_index].y] = robot_index;
                        board[robots[robot_index].x][robots[robot_index].y] = 0;
                        robots[robot_index].x += 1;
                    }
                }
            }
            if (robots[robot_index].dir == DOWN)
            {
                for (j = 0; j < distance; j++)
                {
                    if (robots[robot_index].y - 1 <= 0) // x,y 범위는 1~100. 즉 0이하면 벽에 부딪힘
                    {
                        cout << "Robot " << robot_index << " crashes into the wall" << endl;
                        return 0;
                    }
                    else if (board[robots[robot_index].x][robots[robot_index].y - 1] != 0) // 이동할 보드 위치가 0이 아니면 다른로봇이 존재.
                    {
                        cout << "Robot " << robot_index << " crashes into robot " << board[robots[robot_index].x][robots[robot_index].y - 1] << endl;
                        return 0;
                    }
                    else
                    {
                        board[robots[robot_index].x][robots[robot_index].y - 1] = robot_index;
                        board[robots[robot_index].x][robots[robot_index].y] = 0;
                        robots[robot_index].y -= 1;
                    }
                }
            }
            if (robots[robot_index].dir == UP)
            {
                for (j = 0; j < distance; j++)
                {
                    if (robots[robot_index].y + 1 > Y) // x,y 범위는 1~100. 즉 0이하면 벽에 부딪힘
                    {
                        cout << "Robot " << robot_index << " crashes into the wall" << endl;
                        return 0;
                    }
                    else if (board[robots[robot_index].x][robots[robot_index].y + 1] != 0) // 이동할 보드 위치가 0이 아니면 다른로봇이 존재.
                    {
                        cout << "Robot " << robot_index << " crashes into robot " << board[robots[robot_index].x][robots[robot_index].y + 1] << endl;
                        return 0;
                    }
                    else
                    {
                        board[robots[robot_index].x][robots[robot_index].y + 1] = robot_index;
                        board[robots[robot_index].x][robots[robot_index].y] = 0;
                        robots[robot_index].y += 1;
                    }
                }
            }
        }
    }
    cout << "OK" << endl;
    return 0;
}