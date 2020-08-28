//#include<iostream>
//#include<string>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
///*
//N-Queen 문제는 크기가 N*N인 체스판 위에 퀸N개를 서로 공격할 수 없게 놓는 문제이다. N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오
//*/
//int answer = 0;
//int N;
//vector<pair<int, int>> path;
//void N_Queen(int x, int y,int cnt) {
//	int f =0;
//	if (cnt == N) {
//		cout << endl;
//		answer++;
//		return;
//	}
//
//	for (int i = 0; i < N; i++) {
//		f = 0;
//		if (x + 1 < N && i  < N) {
//			for (int j = 0; j < path.size(); j++) {
//				//가능 하면
//				if (path[j].second != i && i != path[j].second - (x + 1 - path[j].first) && i != path[j].second + (x + 1 - path[j].first)) {
//					f++;
//				}
//				else break;
//			}
//		}
//		if (f == path.size()) {
//			cout << x + 1 << " , " << i << endl;
//			path.push_back(make_pair(x + 1, i));
//			N_Queen(x + 1, i, cnt + 1);
//			path.pop_back();
//
//		}
//	}
//}
//
//
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		path.push_back(make_pair(0, i));
//		cout << 0 << " , " << i << endl;
//		N_Queen(0,i,1);
//		path.clear();
//	}
//
//	cout << answer;
//
//
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N_Queen
/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
*/
vector<vector<bool>>vec(15, vector<bool>(15, false));
vector<pair<int, int>>v_c;
int N = 0;
int answer = 0;
bool check(int x, int y) {

	for (int i = 0; i < v_c.size(); i++) {

		if (v_c[i].second != y) {
			int c_y = x - v_c[i].first;

			if (y != v_c[i].second + c_y && y != v_c[i].second - c_y) {
				continue;
			}
			else return true;

		}
		else return true;
	}
	return false;
}
void dfs(int x, int y) {
	if (x == N - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check(x + 1, i)) {
			continue;
		}
		else {
			v_c.push_back({ x + 1,i });
			dfs(x + 1, i);
			v_c.pop_back();
		}

	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		v_c.push_back({ 0,i });
		dfs(0, i);
		v_c.pop_back();
	}
	cout << answer;

	return 0;
}