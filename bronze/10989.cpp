#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int N, temp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        arr[temp]++;
    }
    
    for(int i=1; i<=10000; i++)
    {
        if (arr[i] != 0)
        {
            for(int j=0; j<arr[i]; j++)
                cout<<i<<"\n";
        }
    }
}