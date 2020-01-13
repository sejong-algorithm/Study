#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(string s) {
	int num = s.size();
	int ans = num;

	for (int i = 1; i <= num / 2; i++) {
		int index = i;
		int cnt = 1;
		string comp;
		string part;
		comp = s.substr(0, i);

		while (index + i <= num) {
			if (!comp.compare(s.substr(index, i))) {
				cnt++;
			}
			else {
				if (cnt != 1) {
					part += to_string(cnt);
					part += comp;
					comp = s.substr(index, i);
				}
				else {
					part += comp;
					comp = s.substr(index, i);
				}
				cnt = 1;
			}
			index += i;
		}
		if (index == num) {
			if (cnt != 1) {
				part += to_string(cnt);
				part += comp;
			}
			else {
				part += comp;
			}
		}
		else {
			if (cnt != 1) {
				part += to_string(cnt);
				part += comp;
				part += s.substr(index, num - index);
			}
			else {
				part += comp;
				part += s.substr(index, num - index);
			}
		}
		int a = part.size();
		ans = min(ans, a);
	}

	return ans;
}