#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool comp(pair<float, int> a, pair<float, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> tmp(N, make_pair(0, 0));
	vector<int> sum(N + 1, 0);
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] > N)continue;
		tmp[stages[i] - 1].first++;
	}
	for (int i = 1; i <= N; i++) {
		sum[i] += sum[i - 1] + tmp[i - 1].first;
		tmp[i - 1].second = i;
		if (sum[i - 1] >= stages.size())tmp[i - 1].first = 0;
		else tmp[i - 1].first = (float)(tmp[i - 1].first / (stages.size() - sum[i - 1]));
	}
	sort(tmp.begin(), tmp.end(), comp);
	for (int i = 0; i < N; i++) {
		answer.push_back(tmp[i].second);
	}

	return answer;
}