#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string str) {
	string answer = "";
	int cnt = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (cnt % 2 == 0)
				answer += str[i] - 32;
			else
				answer += str[i];

			cnt++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (cnt % 2 == 0)
				answer += str[i];
			else
				answer += str[i] + 32;

			cnt++;
		}
		else if (str[i] == ' ')
		{
			cnt = 0;
			answer += str[i];
		}
	}

	return answer;
}
int main()
{
	string str;

	getline(cin, str);

	cout << solution(str) << endl;

	return 0;
}