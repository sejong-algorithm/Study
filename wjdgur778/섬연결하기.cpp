//#include<iostream>
//#include<set>
//#include<vector>
//#include<algorithm>
//using namespace std;
////최소신장트리
//
//// 4	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	
//// 011,131,022,125,238
//// n이 섬의 갯수 , set에 섬을 넣고 최소부터 보면서 check가 되어있지 않고 연결할수 있는지 확인
//// 연결할게 없으면 dec에 넣어볼까
////
//int solution(int n, vector<vector<int>> costs) {
//	int answer = 0;
//	vector<pair<int, pair<int, int>>> vec;
//	set<int> island;
//	for (int i = 0; i < costs.size(); i++) {
//		vec.push_back(make_pair(costs[i][2], make_pair(costs[i][0], costs[i][1])));
//	}
//	sort(vec.begin(), vec.end());
//	answer += vec[0].first;
//	island.insert(vec[0].second.first);
//	island.insert(vec[0].second.second);
//
//	for (int i = 1; i < vec.size(); i++) {
//		int x = 0;
//		int y = 0;
//		if (island.find(vec[i].second.first) == island.end()) {
//			x++;
//		}
//		if (island.find(vec[i].second.second) == island.end()) {
//			y++;
//		}
//		if (x + y == 2) {
//			island.insert(vec[i].second.first);
//			island.insert(vec[i].second.second);
//			answer += vec[i].first;
//			continue;
//		}
//		if (x) {
//			island.insert(vec[i].second.first);
//			answer += vec[i].first;
//		}
//		if (y) {
//			island.insert(vec[i].second.second);
//			answer += vec[i].first;
//		}
//
//
//	}
//	return answer;
//}
//
//int main() {
//	cout << solution(4, { {0,1,1},{3,1,1},{0,2,2},{0,3,2},{0,4,100} });
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

int main()
{

	return 0;
}