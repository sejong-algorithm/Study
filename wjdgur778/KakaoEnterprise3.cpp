#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int n;
int m;
int q;
bool f = false;
int answer = 100;
string goal;
queue<string> qq;
map<string,bool> check;
map<string, vector<pair<string, int>>> sol;

void dfs(string s, int cnt) {

	check[s] = true;
	if (s == goal) {
		f = true;
		answer = min(answer, cnt);
		return;
	}
	if (sol.find(s) == sol.end()) return;

	for (int i = 0; i < sol[s].size(); i++) {
		if (check[sol[s][i].first] == false) {
			dfs(sol[s][i].first, cnt + sol[s][i].second);
		}
		check[s] = false;
	}
	return;
}

int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int c;
		string s1 , s2;
		cin >> s1 >> s2 >> c;
		check[s1] = false;
		if (sol.find(s1) == sol.end()) {
			vector<pair<string, int>> v;
			v.push_back(make_pair(s2, c));
			sol.insert(make_pair(s1, v));
		}
		else {
			sol[s1].push_back(make_pair(s2, c));
		} /*     ooo  :  <oox,2 >,<ooo,3> ,........    */
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int c;
		string s1, s2;
		cin >> s1 >> s2;
		goal = s2;

		if (sol.find(s1) == sol.end()) {
			cout << -1;
			continue;
		}

		dfs(s1, 0);
		if (f) cout << answer << endl;
		else cout << -1;
	}

	
	return 0;
}


