#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long lan_num;
long long slice_num;
long long max_result;
vector<int> lans;

long long get_slices(long long len)
{
    long long result = 0;
    for(int i=0; i<lans.size(); i++)
    {
        result += lans[i] / len;
    }
    return result;
}

void binary_search(long long maxx)
{
    long long start = 1;
    long long end = maxx;
    long long mid = (start + end) / 2;

    while(end-start >= 0)
    {
        long long s = get_slices(mid);
		if(s >= slice_num)
            max_result = max(max_result, mid);
        
        if(s < slice_num)
            end = mid - 1;
        else
 			start = mid + 1;
 		mid= (start + end)/2;
 	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>lan_num>>slice_num;
    int t;
    for(int i=0; i<lan_num; i++)
    {
        cin>>t;
        lans.push_back(t);
    }
    long long maxx = *max_element(lans.begin(), lans.end());
    max_result = 0;
    binary_search(maxx);
    cout<<max_result<<"\n";
}