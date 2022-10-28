#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree_num;
long long wanted_tree_len;
vector<int> trees;

bool get_tree(int h)
{
    long long res = 0;

    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > h)
            res += trees[i] - h;
    }
    
    if (res >= wanted_tree_len)
        return true;
    else
        return false;
}

long long param_search(int left, int right)
{
    long long maxh = 0;
    long long temp;
    long long l = left;
    long long r = right;
    long long mid = (l + r) / 2;

    while (l <= r)
    {  
        if (get_tree(mid))
        {
            maxh = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
        mid = (l + r) / 2;
    }

    return maxh;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>tree_num>>wanted_tree_len;
    int temp;
    for (int i = 0; i < tree_num; i++)
    {
        cin>>temp;
        trees.push_back(temp);
    }

    int maxim = *max_element(trees.begin(), trees.end());
    
    cout<<param_search(0, maxim)<<"\n";
}