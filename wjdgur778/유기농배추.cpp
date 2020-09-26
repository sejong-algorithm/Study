#include<iostream>
using namespace std;


//유기농 배추
//dfs
//완전탐색

int M, N, K;
bool map[50][50] = { 0, };
bool visit[50][50] = { 0, };

void dfs(int x, int y) {

	visit[x][y] = 1;

	if (y < N - 1) {
		if (map[x][y + 1] == 1 && visit[x][y + 1] != 1) {
			dfs(x, y + 1);
		}
	}
	if (y > 0) {
		if (map[x][y - 1] == 1 && visit[x][y - 1] != 1) {
			dfs(x, y - 1);
		}
	}
	if (x > 0) {
		if (map[x - 1][y] == 1 && visit[x - 1][y] != 1) {
			dfs(x - 1, y);
		}
	}
	if (x < M - 1) {
		if (map[x + 1][y] == 1 && visit[x + 1][y] != 1) {
			dfs(x + 1, y);
		}
	}
}

int main() {

	int test;
	int a, b;
	cin >> test;
	int cnt;
	for (int p = 0; p < test; p++) {

		cnt = 0;
		cin >> M >> N >> K;

		for (int k = 0; k < K; k++) {
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}

			}
		}
		cout << cnt << endl;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	}
	return 0;
}
