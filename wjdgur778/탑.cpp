#include <string>
#include <vector>
#include<stack>
using namespace std;

vector<int> solution(vector<int> h) {
	vector<int> answer;
	int i = 1;
	stack<pair<int, int>> s;
	s.push(make_pair(h[0], 1));
	answer.push_back(0);

	for (int i = 1; i < h.size(); i++) {

		if (s.top().first <= h[i]) {
			while (!s.empty() && s.top().first <= h[i])s.pop();
			if (s.empty())answer.push_back(0);
			else {
				answer.push_back(s.top().second);
			}
			s.push(make_pair(h[i], i + 1));
		}
		else {
			answer.push_back(s.top().second);
			s.push(make_pair(h[i], i + 1));
		}

	}
	return answer;
}