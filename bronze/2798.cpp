#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int N, target, temp, min_r;
    vector<int> cards;

    min_r = 0;
    cin>>N>>target;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        cards.push_back(temp);
    }

    for(int i=0; i<cards.size() - 2; i++)
    {
        for(int j=i+1; j<cards.size() - 1; j++)
        {
            for(int k=j+1; k<cards.size(); k++)
            {
                if (target - (cards[i] + cards[j] + cards[k]) >= 0 && \
                target - (cards[i] + cards[j] + cards[k]) < target - min_r)
                    min_r = abs(cards[i] + cards[j] + cards[k]);
            }
        }
    }

    cout<<min_r<<"\n";
}