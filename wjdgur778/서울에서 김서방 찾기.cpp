#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int index = 0;
	answer += "�輭���� ";
	for (int i = 0; i < seoul.size(); i++) {
		if (!seoul[i].compare("Kim"))answer += to_string(i);
	}
	answer += "�� �ִ�";

	return answer;
}