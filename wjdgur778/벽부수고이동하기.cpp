#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include <time.h>
using namespace std;

vector<vector<int>> map(1001, vector<int>(1001, false));
bool check[1001][1001][2];
int n;
int m;
clock_t start, e;



int main() {
	char a;
	queue<pair<pair<int, int>, int>> q;
	cin >> n >> m;
	   
	//input

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			map[i][j] = a - '0';
		}
	}
	start = clock();

	//input for bfs
	q.push(make_pair(make_pair(0, 0), 0));
	check[0][0][0] = true;

	int wall = 0;
	bool f = false;
	int x, y = 0;
	int cnt = 0;
	int answer = 0;
	//bfs
	while (!q.empty()) {

		int size = q.size();
		cnt++;

		for (int i = 0; i < size; i++) {
			x = q.front().first.first;
			y = q.front().first.second;
			wall = q.front().second;
			q.pop(); 
			//check[x][y] = true;
			if (x == n - 1 && y == m - 1) {
				answer = cnt;
				f = true;
				break;
			}
			if (x + 1 < n) {
				if (check[x + 1][y][wall] == false && map[x + 1][y] == 0) {
					check[x + 1][y][wall] = true;
					q.push(make_pair(make_pair(x + 1, y), wall));
				}
				if (wall == 0 && map[x + 1][y] == 1) {
					check[x + 1][y][wall + 1] = true;
					q.push(make_pair(make_pair(x + 1, y), wall + 1));
				}
			}
			if (y + 1 < m) {
				if (check[x][y + 1][wall] == false && map[x][y + 1] == 0) {
					check[x][y + 1][wall] = true;
					q.push(make_pair(make_pair(x, y + 1), wall));
				}
				if (wall == 0 && map[x][y + 1] == 1) {
					check[x][y + 1][wall + 1] = true;
					q.push(make_pair(make_pair(x, y + 1), wall + 1));
				}
			}
			if (x - 1 >= 0) {
				if (check[x - 1][y][wall] == false && map[x - 1][y] == 0) {
					check[x - 1][y][wall] = true;
					q.push(make_pair(make_pair(x - 1, y), wall));
				}
				if (wall == 0 && map[x - 1][y] == 1) {
					check[x - 1][y][wall - 1] = true;
					q.push(make_pair(make_pair(x - 1, y), wall + 1));
				}
			}
			if (y - 1 >= 0) {
				if (check[x][y - 1][wall] == false && map[x][y - 1] == 0) {
					check[x][y - 1][wall] = true;
					q.push(make_pair(make_pair(x, y - 1), wall));
				}
				if (wall == 0 && map[x][y - 1] == 1) {
					check[x][y - 1][wall + 1] = true;
					q.push(make_pair(make_pair(x, y - 1), wall + 1));
				}
			}

		}
		if (f) break;
	}

	if (answer == 0)cout << -1;
	else cout << answer;
	return 0;
}