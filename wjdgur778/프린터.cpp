#include <string>
#include <vector>
#include<deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	deque <pair<int, int>> a;
	int answer = 0;
	int cnt = 0;
	int size = a.size();
	pair <int, int> ans = make_pair(priorities[location], location);
	bool flag = true;

	for (int i = 0; i < priorities.size(); i++) {
		a.push_back(make_pair(priorities[i], i));
	}

	while (!a.empty()) {
		for (int j = 1; j < a.size(); j++) {
			if (a.front().first < a[j].first) {
				a.push_back(a.front());
				a.pop_front();
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
			if (ans.first == a.front().first &&a.front().second == ans.second) return cnt;
			else {
				a.pop_front();
			}
		}
		flag = true;

	}
	return 0;
}