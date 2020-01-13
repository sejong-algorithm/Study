#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = ""; // 97~122, 65~90
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			answer += ' ';
			continue;
		}
		if ((int)s[i] <= 90 && (int)s[i] + n > 90) {
			answer += (int)s[i] + n - 26;
			continue;
		}
		if ((int)s[i] + n > 122) {
			answer += (int)s[i] + n - 26;
			continue;
		}
		answer += (int)s[i] + n;
	}

	return answer;
}