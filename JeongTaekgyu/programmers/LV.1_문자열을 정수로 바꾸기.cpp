#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(string s) {
	int answer = 0;

	answer = atoi(s.c_str());

	return answer;
}
int main()
{
	string s;
	
	std::cin >> s;

	std::cout << solution(s) << std::endl;

	return 0;
}