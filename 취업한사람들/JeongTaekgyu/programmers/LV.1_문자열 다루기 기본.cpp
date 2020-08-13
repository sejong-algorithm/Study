#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool solution(string s) {
	bool answer = true;

	if (s.size() == 4 || s.size() == 6)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (!(s[i] >= 48 && s[i] <= 57))
				answer = false;
		}
	}
	else
	{
		answer = false;
	}

	return answer;
}
int main()
{
	std::string s;

	std::cin >> s;

	std::cout << s << std::endl;
	
	std::cout << solution(s) << std::endl;

	return 0;
}