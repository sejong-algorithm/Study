#include <string>
#include <vector>

using namespace std;

int solution(string a) {
	int answer = 0;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '(') {
			cnt++;
			flag = true;
		}
		else {
			if (flag) {
				cnt--;
				answer += cnt;
				flag = false;
				continue;
			}
			else {
				cnt--;
				answer++;
			}
		}
	}
	return answer;
}