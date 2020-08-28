#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<string> map, t_map;
vector<vector<bool>> check(30, vector<bool>(30, false));
int m_1;
int n_1;
int cnt = 0;
int result = 0;

void down(int m, int n) {
	int tmp = 1;
	for (int i = m - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (t_map[i][j] != '*' && t_map[i + 1][j] == '*') {

				while ((i + tmp) < m && t_map[i + tmp][j] == '*' ) {
					tmp++;
				}

				t_map[i + tmp - 1][j] = t_map[i][j];
				check[i + tmp - 1][j] = false;
				t_map[i][j] = '*';
				tmp = 1;
			}

		}
	}
}


void dfs(int x, int y) {
	cnt++;
	check[x][y] = true;
	if (x + 1 < m_1 && y + 1 < n_1) {
		if (map[x][y] != '*' && map[x][y] == map[x][y + 1] && map[x][y] == map[x + 1][y + 1] && map[x][y] == map[x + 1][y]) {

			if (check[x][y + 1] == false) {
				dfs(x, y + 1);
			}
			if (check[x + 1][y + 1] == false) {
				dfs(x + 1, y + 1);
			}
			if (check[x + 1][y] == false) {
				dfs(x + 1, y);
			}
		}
	}
	t_map[x][y] = '*';
	return;

}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	map = board;
	t_map = board;
	m_1 = m;
	n_1 = n;
	bool flag = true;

	while (flag) {
		flag = false;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {

				if (check[i][j] == false) {
					if (map[i][j] != '*' && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1] && map[i][j] == map[i + 1][j]) {
						dfs(i, j);
						result += cnt;
						cnt = 0;
						flag = true;
					}
				}

			}
		}

		if (flag == false) break;
		down(m, n);
		map.clear();
		map.assign(t_map.begin(), t_map.end());

	}
	return result;
}
int main() {

	cout << solution(6, 6, { "AAAAAA", "AAAAAA", "AACCAC", "AAAAAA", "AAAAAA", "AAAAAA" });


	return 0;
}