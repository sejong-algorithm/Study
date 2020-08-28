//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////누가봐도 greedy
//
//
//int result = 0;
//int N;
//int K;
//int W;
//int V;
//vector<pair<int, int>>bag;
//
//bool comp(pair<int, int>a, pair<int, int>b) {
//	if (a.first == b.first) return a.second < b.second;
//	else return a.first > b.first;
//}
//
//int main()
//{
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		int w, v;
//		cin >> w >> v;
//		bag.push_back({ v,w });
//	}
//	sort(bag.begin(), bag.end(),comp);
//	// K가 한계
//	for (int i = 0; i < N; i++) {
//		int t_ans = 0;
//		int sum = 0;
//		int j = i;
//		while ( j<bag.size()) {
//				sum += bag[j].second;
//				if (sum <= K)
//					t_ans += bag[j].first;
//				else sum -= bag[j].second;
//			j++;
//		}
//		result = max(result, t_ans);
//	}
//
//	cout << result;
//	return 0;
//
//}

/*
9 10


4 10
5 10
1 8
3 7
4 7
4 7
2 6
4 5
1 4



*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int result = 0;
int N;
int K;
int W;
int V;
vector<pair<int, int>>bag;
vector<int>dp(100001,0);
int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		for (int j = K; j >= W; j--) {
			dp[j] = max(dp[j - W] + V, dp[j]);
		}
	}
	cout << dp[K];

	return 0;
}