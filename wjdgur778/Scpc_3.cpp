#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;

int Answer;
int n, m, k;
vector <vector<pair<int, int>>> map;
int t_ans = 0;
void dfs(int n, int dest,int level,int cnt) {
	if (n == dest) {

		 
		return;
	}
	for (int i = 0; i < map[n].size(); i++) {
		if (map[n][i].second > level) {
			dfs(map[n][i].first, dest, map[n][i].second,cnt+1);
		}
	}
} 
int main(int argc, char** argv)
{
	int T, test_case;


	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> n >> m >> k;
		vector <vector<pair<int, int>>> vec(n+1);
		map = vec;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back({ b,i + 1 });
			vec[b].push_back({ a,i + 1 });
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			t_ans = 0;
			dfs(a, b, 0, 1);
			Answer += m - t_ans;
		}



		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}