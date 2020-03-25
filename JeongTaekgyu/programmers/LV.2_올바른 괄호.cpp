#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack<char> st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')' && !(st.empty()) )
		{
			st.pop();
		}
		else if (s[i] == ')' && st.empty() )
		{
			return false;
		}
	}

	if (st.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string s;

	cin >> s;
	
	cout << solution(s) << endl;

	return 0;
}