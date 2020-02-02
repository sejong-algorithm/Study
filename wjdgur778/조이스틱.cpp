#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;

int main() {
	int answer = 0;
	int a = 0;
	int b = 0;
	int cnt = 0;
	int r = 0;
	int l = 0;
	int start = 0;
	int end = 0;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')cnt++;
		else {
			answer += (s[i] - 65) > 13 ? 26 - (s[i] - 65) : s[i] - 65;
		}
	}
	if (cnt > 0) {

		for (int i = 0, j = s.size(); i < s.size() / 2 , j >= s.size() / 2; i++, j--) {

			if (s[i] != 'A') {
				r = i;
				if (start == 0) {
					start = i;
				}
			}

			if (s[s.size() - i] != 'A') {
				l = i;
				if (end == 0) {
					end = i;
				}
			}

		}

		a = min(s.size() - start, s.size()- end);
		b = min(2 * r + l, 2 * l + r);
		a = min(a, b);
	}

	else {
		answer += (s.size() - 1);
	}

	answer += a;
	cout << answer;
	return 0;
}
