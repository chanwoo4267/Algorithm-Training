#include <iostream>
#include <cstring>
using namespace std;

#define MAX_FIELD 250
#define VISITED -1
#define EMPTY 0
#define WALL 1
#define WOLF 2
#define SHEEP 3

int R, C;
int field[MAX_FIELD + 3][MAX_FIELD + 3];
int dirr[4] = {1, -1, 0, 0};
int dirc[4] = {0, 0, 1, -1};
int wolfnum, sheepnum;
int finalwolf, finalsheep;
bool outofrange;

void dfs();
void visitall(int r, int c);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    finalwolf = 0;
    finalsheep = 0;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
        {
            char t;
            cin>>t;
            switch(t)
            {
                case '.':
                    field[i][j] = EMPTY; break;
                case '#':
                    field[i][j] = WALL; break;
                case 'v':
                    field[i][j] = WOLF; break;
                case 'k':
                    field[i][j] = SHEEP; break;
            }
        }

   dfs();

   cout<<finalsheep<<" "<<finalwolf<<"\n";
   return 0;
}

void dfs()
{
    int i,j;

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if (field[i][j] != VISITED && field[i][j] != WALL)
            {
                wolfnum = 0;
                sheepnum = 0;
                outofrange = false;
                visitall(i, j);
                if (!outofrange)
                    wolfnum < sheepnum ? finalsheep += sheepnum : finalwolf += wolfnum;
            }
        }
    }
}

void visitall(int r, int c)
{
    if (field[r][c] == VISITED)
        return;
    else
    {
        if (field[r][c] == WOLF)
            wolfnum++;
        else if (field[r][c] == SHEEP)
            sheepnum++;
        field[r][c] = VISITED;
    }
    
    for(int i=0; i<4; i++)
    {
        int nextr = r + dirr[i];
        int nextc = c + dirc[i];
        if (nextr >= 1 && nextr <= R && nextc >= 1 && nextc <= C && field[nextr][nextc] != WALL)
            visitall(nextr, nextc);
    }
}