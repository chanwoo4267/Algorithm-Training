#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int v_num, e_num;
int ag[401][401];

int main()
{
    cin>>v_num>>e_num;
    memset(ag, 0, sizeof(ag));

    for(int i=1; i<=400; i++)
        for(int j=1; j<400; j++)
            if (i == j) ag[i][j] = 0;

    for(int i=0; i<e_num; i++)
    {
        int v1, v2, dist;
        cin>>v1>>v2>>dist;
        ag[v1][v2] = dist;
    }

    for(int k=1; k<=v_num; k++)
        for(int i=1; i<=v_num; i++)
            for(int j=1; j<=v_num; j++)
            {
                if (ag[i][k] && ag[k][j])
                {
                    if (!ag[i][j])
                        ag[i][j] = ag[i][k] + ag[k][j];
                    else
                        ag[i][j] = min(ag[i][j], ag[i][k] + ag[k][j]);
                }
            }

    int result = INT_MAX;

    for(int i=1; i<=v_num; i++)
        if (ag[i][i] != 0 && ag[i][i] < result)
            result = ag[i][i];

    if (result == INT_MAX)
        cout<<"-1"<<endl;
    else
        cout<<result<<endl;
}
