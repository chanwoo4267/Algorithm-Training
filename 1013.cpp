#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(void)
{
	int N;
	std::cin >> N;
	for (int t = 0; t < N; t++)
    {
		string str;
        cin>>str;

        regex pattern("(100+1+|01)+");
        if (regex_match(str, pattern))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}