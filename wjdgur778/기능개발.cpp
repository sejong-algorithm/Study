#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
	vector<int> answer;
	queue <int> q;
	int n = 0;
	for (int i = 0; i < p.size(); i++) {
		n = (99 - p[i]) / s[i] + 1;
		if (i == 0) {
			q.push(n);
			continue;
		}
		if (q.front() >= n) q.push(n);
		else {
			answer.push_back(q.size());
			while (!q.empty()) q.pop();
			q.push(n);
		}
	}
	answer.push_back(q.size());
	return answer;
}