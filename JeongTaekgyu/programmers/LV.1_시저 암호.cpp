#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string str, int n) {
	string answer = "";

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] + n > 'z')
				str[i] = 65 + (n - 1) - (90 - str[i]);
			else
				str[i] += n % 26;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + n > 'Z')
				str[i] = 97 + (n - 1) - (122 - str[i]);
			else
				str[i] += n % 26;
		}
		answer += str[i];
	}

	return answer;
}
int main()
{
	string str;
	int n;

	std::getline(std::cin, str);
	cin >> n;

	cout << solution(str, n) << endl;

	return 0;
}