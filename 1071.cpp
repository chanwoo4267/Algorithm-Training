#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int N;
int cnt;

int main()
{
    cin>>N;
    arr.clear();
    for(int i=0; i<N; i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<N-1; i++)
    {
        if (arr[i] + 1 == arr[i+1])
        {
            auto it = lower_bound(arr.begin() + i, arr.end(), arr[i] + 2);
            if (it != arr.end())
                swap(*it, arr[i+1]);
            else
            {
                auto ub = upper_bound(arr.begin() + i + 1, arr.end(), arr[i]);
                auto lb = lower_bound(arr.begin() + i - cnt, arr.end(), arr[i]);
                while (ub != arr.end())
                {
                    swap(*lb, *ub);
                    lb++; ub++;
                }
            }
            cnt = 0;
        }
        else if (arr[i] == arr[i+1])
            cnt += 1;
    }

    for(int i=0; i<N; i++)
        cout<<arr[i]<<" ";
}