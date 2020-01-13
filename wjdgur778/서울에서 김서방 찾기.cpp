#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int index = 0;
	answer += "김서방은 ";
	for (int i = 0; i < seoul.size(); i++) {
		if (!seoul[i].compare("Kim"))answer += to_string(i);
	}
	answer += "에 있다";

	return answer;
}