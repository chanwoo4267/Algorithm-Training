#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> grade;
    int N;
    int temp;

    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>temp;
        grade.push_back(temp);
    }

    int max_grade = *max_element(grade.begin(), grade.end());
    double total_grade = 0;
    for(int i=0; i<grade.size(); i++)
        total_grade += (double)(grade[i]) * 100 / max_grade;
    total_grade /= grade.size();
    cout<<total_grade<<"\n";
}