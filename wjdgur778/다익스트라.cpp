#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int INF = 98765432;
int u = 0;
int v = 0;
int w = 0;
vector<pair<int, int>> vec[20001];

vector<int> dst(int vertex, int start) {

	vector<int> dist(vertex, INF);
	dist[start] = 0;
	vector<bool>check(vertex, false);
	priority_queue<pair<int, int>> p_q;

	p_q.push(make_pair(0, start));

	while (!p_q.empty()) {

		int cost = -p_q.top().first;
		int cur = p_q.top().second;
		//cout << cur << endl;
		p_q.pop();

		if (dist[cur] < cost) {
			continue;
		}

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int ncost = cost + vec[cur][i].second;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				p_q.push(make_pair(-ncost, next));
			}

		}
	}

	return dist;
}
int main(void)
{
	int n, m, s;
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v, w));
	}

	vector<int> answer = dst(++n, s);

	for (int i = 1; i < n; i++)
	{
		if (answer[i] == INF)
			cout << "INF\n";
		else
			cout << answer[i] << "\n";
	}

	return 0;
}