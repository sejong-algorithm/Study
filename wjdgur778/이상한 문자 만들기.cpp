#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	s.push_back(' ');
	string answer = "";
	string temp = "";
	int i = 0;
	int index = 0;
	while (i <= s.size()) {
		if (s[i] != ' ') {
			temp += s[i];
		}
		else {
			for (int j = 0; j < temp.size(); j++) {
				if (j % 2 == 0) {
					answer += toupper(temp[j]);
				}
				else { answer += tolower(temp[j]); }
			}
			if (i != s.size() - 1) answer += ' ';
			temp.clear();
		}
		i++;
	}
	return answer;
}