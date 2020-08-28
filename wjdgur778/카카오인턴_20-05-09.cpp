#include <string>
#include<iostream>
#include<stack>
using namespace std;


int solution(string dartResult) {
	stack<int> s;
	int answer = 0;
	int sum = 0;
	string tmp = "";
	int t;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == '#') {
			s.top() = s.top() * (-1);
		}
		else if (dartResult[i] == '*') {
			if (s.size() == 1) {
				sum += s.top() * 2;
				s.pop();
			}
			else {
				int cnt = s.top();
				s.pop();
				cnt += s.top();
				cnt *= 2;
				s.pop();
				sum += cnt;
			}
		}
		else {
			if (dartResult[i] == 'S') {
				s.push(stoi(tmp));
				tmp = "";
			}
			else if (dartResult[i] == 'D') {
				t = stoi(tmp);
				s.push(t * t);
				tmp = "";
			}
			else if (dartResult[i] == 'T') {
				t = stoi(tmp);
				s.push(t * t * t);
				tmp = "";
			}
			else {
				tmp += dartResult[i];
			}

		}
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	return sum;
}
int main() {

	cout << solution("1D#2S*3S");
	return 0;
}