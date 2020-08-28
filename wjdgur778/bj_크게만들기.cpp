#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

/*  ( 1 ≤ K <N ≤ 500,000 )  */
/*
4 2
1924

6 3
162748 -> 748
654321
<after sorting>
vec : 876421
ind : 135246
인덱스가 n - k 이상이어야함 ex(3)
<logic>

*/

int main()
{
	//init
	int k;
	int n;

	vector<pair<int, int>> number;
	queue<pair<int, int>>q;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		number.push_back(make_pair(a-'0', n - i));
	}
	sort(number.begin(), number.end(), greater<pair<int, int>>());
	for (int i = 0; i < n; i++) {
		q.push(number[i]);
	}
	int cnt = 0;
	int ii = 0;
	int tmp = 0;
	bool f = true;
	while (cnt != n - k) {
		if (f) {
			if (q.front().second >= n - k) {
				cout << q.front().first;
				tmp = q.front().second;
				cnt++;
				f = false;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		else {
			if (q.front().second < tmp) {
				cout << q.front().first;
				tmp = q.front().second;
				cnt++;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}