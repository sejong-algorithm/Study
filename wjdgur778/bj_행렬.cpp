#include<iostream>
#include<vector>
using namespace std;

int main() {
	//init


	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<vector<int>>A(n,vector<int>(m));
	vector<vector<int>>B(n, vector<int>(m));
	for (int j = 0; j < n; j++) {
		for (int jj = 0; jj < m; jj++) {
			char a;
			cin >> a;
			A[j][jj] = a - '0';
		}
	}
	int b = 0;
	for (int j = 0; j < n; j++) {
		for (int jj = 0; jj < m; jj++) {
			char a;
			cin >> a;
			B[j][jj] = a - '0';
		}
	}
	//logic
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			int cnt = 0;
			//8-ways
			for (int ii = 0; ii < 3; ii++) {
				for (int jj = 0; jj < 3; jj++) {
					if (A[i + ii][j + jj] != B[i + ii][j + jj])cnt++;
				}
			}
			if (cnt % 2 != 0)answer++;
		}
	}

	cout << answer;
	return 0;
}