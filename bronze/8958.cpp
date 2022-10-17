#include <iostream> 
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int streak, N, score;
    string str;

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>str;
        streak = 0;
        score = 0;
        for(int j=0; j<str.length(); j++)
        {
            if (str[j] == 'O')
            {
                streak += 1;
                score += streak;
            }
            else
                streak = 0;
        }
        cout<<score<<"\n";
    }
}