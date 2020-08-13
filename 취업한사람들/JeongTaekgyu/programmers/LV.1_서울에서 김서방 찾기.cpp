#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	string x;

	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim")
			x += to_string(i);	//to_string 은 int를 string으로 변환해주는 함수
	}
	answer += x;
	answer += "에 있다";

	return answer;
}
int main()
{
	vector<string> seoul = {"jane","jeong","lee","Kim","kang"};

	std::cout << solution(seoul) << std::endl;

	return 0;
}