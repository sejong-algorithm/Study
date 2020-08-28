//#include<iostream>
//#include<vector>
//#include<queue>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int n;
//int m;
//vector<vector<int>>vec(50, vector<int>(50));
//vector<vector<int>>check(50, vector<int>(50));
//
//int x_way[4] = { 0,1,-1,0 };
//int y_way[4] = { 1,0,0,-1 };
//// 치킨집이 많고 원하는 치킨집은 적을때
//// 
//int bfs_1(int x, int y) {
//	queue<pair<int, int>>q;
//	vector<vector<bool>>visit(50, vector<bool>(50, false));
//
//	q.push({ x,y });
//	int cnt = 0;
//	while (!q.empty()) {
//		int size = q.size();
//
//		cnt++;
//		for (int i = 0; i < size; i++) {
//
//			for (int j = 0; j < 4; j++) {
//				int nx = q.front().first + x_way[j];
//				int ny = q.front().second + y_way[j];
//				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//					if (visit[nx][ny] == false) {
//						visit[nx][ny] = true;
//						q.push({ nx, ny });
//
//						if (vec[nx][ny] == 2) {
//							return  cnt;
//							//cout << nx << " " << ny << endl;
//						}
//					}
//				}
//
//			}
//			q.pop();
//		}
//
//	}
//	return 0;
//}
//void bfs(int x, int y) {
//	queue<pair<int, int>>q;
//	vector<vector<bool>>visit(50, vector<bool>(50, false));
//
//	q.push({ x,y });
//	int cnt = 0;
//	while (!q.empty()) {
//		int size = q.size();
//
//		cnt++;
//		for (int i = 0; i < size; i++) {
//
//			for (int j = 0; j < 4; j++) {
//				int nx = q.front().first + x_way[j];
//				int ny = q.front().second + y_way[j];
//				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
//					if (visit[nx][ny] == false) {
//						visit[nx][ny] = true;
//						q.push({ nx, ny });
//
//						if (vec[nx][ny] == 2) {
//							check[nx][ny] += cnt;
//							//cout << nx << " " << ny << endl;
//						}
//					}
//				}
//
//			}
//			q.pop();
//		}
//
//	}
//	return;
//}
//
//int main()
//{
//	//init
//	int answer = 99999999;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> vec[i][j];
//		}
//	}
//	//logic
//	//1. if m==1
//	if(m==1){
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (vec[i][j] == 1) {
//					int a = 0;
//					//	cout << a;
//					bfs(i, j);
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (check[i][j] != 0) {
//					answer = min(answer, check[i][j]);
//				}
//			}
//		}
//		cout << answer;
//		//return 0;
//	}
//
//
//
//	else {
//		answer = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (vec[i][j] == 1) {
//				answer +=	bfs_1(i, j);
//				}
//			}
//		}
//		cout << answer;
//		//return 0;
//	}
//
//	
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << check[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//
//brute force : combination
//you have to know a whole map
// 1 -> 2 -> 3 
// 

/*
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2

*/
const int INF = 987654321;
vector<vector<int>>map(50, vector<int>(50));
vector<pair<int, int>>chicken, house;
vector<bool>check(13);
int N, M;
int answer = INF;
int cnt = 0;
int distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int n) {

	if (n == M) {
		int t_ans = 0;
		for (int i = 0; i < house.size(); i++) {
			int m_tmp = INF;
			for (int j = 0; j < chicken.size(); j++) {
				if (check[j] == true) {
					m_tmp = min(m_tmp, distance(chicken[j], house[i]));
				}
			}
			t_ans += m_tmp;
		}
		answer = min(answer, t_ans);
		return;
	}

	if (idx == chicken.size())
		return;

	check[idx] = true;
  	dfs(idx + 1, n + 1);
	check[idx] = false;
	dfs(idx + 1, n);
}

int main() {
	//init
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				house.push_back({ i,j });
			}
			if (a == 2) {
				chicken.push_back({ i,j });
			}
			map[i][j] = a;
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}