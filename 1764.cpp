#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<string, int> mapp;
    vector<string> vect;
    int n, m;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        mapp[str]++;
    }
    for (int i = 0; i < m; i++) 
    {
        cin >> str;
        if (mapp[str] == 1)
            vect.push_back(str);
    }
    sort(vect.begin(), vect.end());
    cout << vect.size() << endl;
    vector<string>::iterator iter;
    for (iter = vect.begin(); iter != vect.end(); iter++)
    {
        cout << *iter;
        if (iter + 1 != vect.end())
            cout << endl;
    }
}