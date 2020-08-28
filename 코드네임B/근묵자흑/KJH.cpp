//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main() {
//	int n, k;
//	vector<pair<int, int>>vec,tmp;
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		vec.push_back({ a,i });
//	}
//	tmp = vec;
//	sort(tmp.begin(), tmp.end());
//
//	for (int i = 0; i < n - 1; i++) {
//		if (tmp[i].first == tmp[i + 1].first) {
//			vec[tmp[i].second].first = 0;
//		}
//		else {
//			vec[tmp[i].second].first = 0;
//			break;
//		}
//	}
//	int i=0;
//	int cnt = 0;
//	while (i<n) {
//		bool f = true;
//		int cur = i;	
//
//		for (; i < cur + k; i++) {
//			if (i < n) {
//				if (vec[i].first == 0) {
//					f = false;
//				}
//			}
//			else break;
//		}
//		if (f && i !=n) {
//			i-= 1;
//		}
//		cnt++;
//	}
//	cout << cnt;
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long ans = 0;
		long long special = 0;
		long long normal = 0;
		cin >> special >> normal;
		ans = min(special / 5, (special + normal) / 12);
		cout << ans << endl;
	}
	return 0;
}