#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	/*

	DP[K][N] = ¥Ò(DP[K-1][N-L])
	L => 0 <= L <= N

*/
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			long long sum = 0;
			for (int ii = 0; ii <= j; ii++) {
				dp[i][j] += dp[i - 1][j - ii] % 1000000000;
				dp[i][j] %= 1000000000;
			}
		}
	}
	/*
	int re = 0;
	for (int i = 0; i <= n; i++) {
		re += dp[k][i] % 1000000000;
	}
	*/
	cout << dp[k][n];

	return 0;
}