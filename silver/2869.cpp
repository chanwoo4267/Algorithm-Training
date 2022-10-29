#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height, timer;
int A, B, V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>A>>B>>V;

    timer = (V - A) / (A - B);
    height = V - (A - B) * timer;

    while (1)
    {
        height -= A;
        timer++;
        if (height <= 0)
            break;
        height += B;
    }

    cout<<timer<<"\n";
}