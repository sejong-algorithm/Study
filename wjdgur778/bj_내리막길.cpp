#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int m, n;
vector<vector<int>>vec(501, vector<int>(501, 0));
vector<vector<bool>>check(501, vector<bool>(501, false));
vector<vector<int>>ans(501, vector<int>(501, -1));

int x_way[4] = {0,1,0,-1};
int y_way[4] = {1,0,-1,0};
int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	if (ans[x][y] == -1) {
		ans[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int n_x = x + x_way[i];
			int n_y = y + y_way[i];
			if (n_x >= 0 && n_y >= 0 && n_x < n && n_y < m) {
				if (vec[x][y] > vec[n_x][n_y]) {
					//check[n_x][n_y] = true;
					ans[x][y] += dfs(n_x, n_y);
					//check[n_x][n_y] = false;
				}
			}
		}
	}
	return ans[x][y];
}



int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}
	ans[n - 1][m - 1] = 1;
	dfs(0, 0);
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout<<ans[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	cout << ans[0][0];
	return 0;

}