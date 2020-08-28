#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

//7 
//  7 2 1 4 5 1 3 3  : 8

int main() {
	int n = -1;
	long long a = 0;
	while (n != 0) {
		long long answer = 0;
		long long width = 0;
		stack<pair<long, long>> stak;
		pair<long, long> tmp(0, 0);
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i <= n; i++) {
			if (i != n)
				cin >> a;
			else a = 0;
			while (!stak.empty() && a < stak.top().first) {
				tmp = stak.top();
				stak.pop();
				if (stak.empty()) {
					width = i;
				}
				else {
					width = i - stak.top().second - 1;
				}
				answer = max(answer, width * tmp.first);

			}
			stak.push(make_pair(a, i));
		}
		cout << answer << endl;
	}

	return 0;

}