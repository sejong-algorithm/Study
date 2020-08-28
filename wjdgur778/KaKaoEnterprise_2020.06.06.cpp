


/*
입력
3
a 2 b 0
a 2 c 1
b 2 a 1
b 0 c 2
c 0 a 2
c 1 b 2
*/
/*
출력
a 3 4
b 2 -2
c 1 -2
*/
/*
입력2
4
drx 2 t1 1
drx 1 gen 2
t1 1 gen 2
t1 2 drx 1
kt 1 drx 2
t1 0 kt 2
drx 2 kt 1
gen 1 t1 2
gen 2 kt 0
gen 1 drx 2
kt 0 t1 2
kt 2 gen 0
*/
/*
출력2
drx 4 2
gen 3 0
t1 3 0
kt 2 -2
*/
//#include <iostream>
//#include <vector>
//#include<algorithm>
//#include<map>
//#include<string>
//using namespace std;
//
//
//bool compare(pair<string, pair<int, int>> & a, pair <string, pair<int, int>> & b) {
//
//	if (a.second.second == b.second.second) {
//		if (a.first.length() == b.first.length()) {
//			return a.first.length() < b.first.length();
//		}
//		else {
//			return a.first < b.first;
//		}
//	}
//	if (a.second.first != b.second.first) return a.second.first > b.second.first;
//	else {
//		return a.second.second > b.second.second;
//	}
//
//}
//
//
//int main() {
//	char input[100];
//	map <string, pair<int, int>> m;
//	string tmp_o;
//	string tmp_t;
//
//	int a = 0;
//	int b = 0;
//	int n = 0;
//
//	cin >> n;
//
//	for (int i = 0; i < (n * (n - 1)); i++) {
//		cin >> tmp_o >> a >> tmp_t >> b;
//		if (a > b) {
//
//			if (m.find(tmp_o) == m.end()) {
//				m.insert(make_pair(tmp_o, make_pair(1, a)));
//				m[tmp_o].second -= b;
//
//			}
//			else {
//				m[tmp_o].first = m[tmp_o].first + 1;
//				m[tmp_o].second += a;
//				m[tmp_o].second -= b;
//			}
//
//			if (m.find(tmp_t) == m.end()) {
//				m.insert(make_pair(tmp_t, make_pair(0, b)));
//				m[tmp_t].second -= a;
//
//			}
//			else {
//				m[tmp_t].second += b;
//				m[tmp_t].second -= a;
//			}
//		}
//		else {
//			if (m.find(tmp_o) == m.end()) {
//				m.insert(make_pair(tmp_o, make_pair(0, a)));
//				m[tmp_o].second -= b;
//
//			}
//			else {
//				m[tmp_o].second += a;
//				m[tmp_o].second -= b;
//			}
//
//			if (m.find(tmp_t) == m.end()) {
//				m.insert(make_pair(tmp_t, make_pair(1, b)));
//				m[tmp_t].second -= a;
//
//			}
//			else {
//				m[tmp_t].first = m[tmp_t].first + 1;
//				m[tmp_t].second += b;
//				m[tmp_t].second -= a;
//			}
//
//		}
//
//	}
//	vector<pair<string,pair<int, int>>> vec;
//
//
//	map<string,pair<int,int> >::iterator it2;
//	for (it2 = m.begin(); it2 != m.end(); it2++)
//	{
//		vec.push_back(make_pair(it2->first, make_pair(it2->second.first, it2->second.second)));
//
//	}
//
//
//	sort(vec.begin(), vec.end(), compare);
//
//	for (int i = 0; i<vec.size(); i++) {
//		cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second;
//		if (i != vec.size()-1) cout << endl;
//	}
//	return 0;
//}


/*
입력1
2 3
6.3
4.3
출력1
3.15



입력2
18 300
51.28
96.87
96.86
48.63
87.83
51.29
56.72
38.05
3.88
79.40
33.43
30.75
13.12
67.80
20.15
96.71
95.93
10.91

출력2
3.20

*/
#include<iostream>
#include<string>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<double> v;
	double answer;
	//갯수
	int N;
	cin >> N;

	//완료되었을때 갯수
	int k;
	cin >> k;
	double start = clock();
	double e;
	double s = 1;
	for (int i = 0; i < N; i++) {
		//double a;
		//cin >> a;
		double a = rand();
		a *= 1000;
		//cout << a << endl;
		e = max(e, a);
		v.push_back(a);
	}
	while (s<= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) { 
			cnt += v[i] / mid;
		}
		if (cnt >= k) {
			answer = mid; 
			s = mid + 1; 
		}
		else { //그 외의 경우
			e = mid - 1; 
		}
	}
	answer = answer / 1000.0;

	double end= clock();
	cout << endl;
	cout << "time : "<<(double)(end- start);
	cout << endl;
	
	cout << fixed;
	cout.precision(2);
	cout << answer;/*
	cout << ceil(answer * 100) / 100 << endl;*/

	//cout << ceil(r * 1000) / 1000 << endl;
	return 0;
}

//#include <string>
//#include <vector>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//string s;
//string target;
//vector<string> words;
//vector<int> check(50, 0);
//int answer = 50;
//void dfs(int n, int m, string s) {
//
//	if (s == target) {
//		answer = min(answer, m);
//		return;
//	}
//
//	for (int i = 0; i < words.size(); i++) {
//		int size = words[i].size();
//		int cnt = 0;
//
//		if (check[i] == false) {
//
//			for (int j = 0; j < size; j++) {
//				if (s[j] != words[i][j]) {
//					cnt++;
//				}
//			}
//
//			if (cnt == 1) {
//				check[i] = true;
//				dfs(i, m + 1, words[i]);
//				check[i] = false;
//			}
//		}
//	}
//}
//
//int solution(string b, string t, vector<string> w) {
//	bool f = false;
//	words = w;
//	target = t;
//	for (int i = 0; i < words.size(); i++) {
//		if (target == words[i]) {
//			f = true;
//		}
//	}
//	if (f) {
//		dfs(0, 0, b);
//	}
//	else return 0;
//
//	return answer;
//}

//int main() {
//
//	cout << solution("hit", "cog", { "hot" ,"dot","dog", "lot","log","cog" });
//	return 0;
//}
																																					