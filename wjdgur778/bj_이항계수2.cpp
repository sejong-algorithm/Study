#include<iostream>
#include<vector>
using namespace std;

//10007로 나눈 나머지를 출력한다.
/*

1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1

*/
int main() {
	vector<vector<int>>dp(1001, vector<int>(1001, 1));
	int N;
	int K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j || j == 0) { 
				dp[i][j] = 1; continue;
			}
			else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%10007;
		}
	}
	cout << dp[N][K];

	return 0;
}
