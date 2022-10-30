#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string str;

bool test(stack<char> *s, char testc)
{
    if (!(*s).empty() && (*s).top() == testc)
    {
        (*s).pop();
        return true;
    }
    else
    {
        cout<<"no\n";
        return false;
    }
}

int main()
{
	while (1)
	{
		getline(cin, str);
		stack<char> s;

		if (str[0] == '.') 
            break;

		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == '(') 
                s.push('(');
			else if (str[i] == '[') 
                s.push('[');
            else if (str[i] == ')')
			{
                if (!test(&s, '('))
                    break;
			}
			else if (str[i] == ']')
			{
				if (!test(&s, '['))
                    break;
			}
	
			if (s.empty() && i == str.length() - 2) 
                cout<<"yes\n";
			else if (!s.empty() && i == str.length() - 2) 
                cout<<"no\n";
		}
	}
}