//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<pair<int, int>> dirty;
//vector<pair<int, int>> star;
//vector<vector<int>> map(20, vector<int>(20, 0));
//
//int n;
//bool ans_f = false;
//int ans_cnt = 0;
//int answer = 0;
///*
//8
//0 0 0 0 0 2 0 0
//0 0 0 0 0 0 1 0
//0 0 2 1 0 0 2 0
//0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0
//0 0 0 2 1 0 0 0
//0 0 0 0 0 0 2 0
//0 0 0 0 0 0 0 0
//*/
//
////star가 하나만 있을때 까지 divide ,, and => conquer
////이때 dirty가 하나라도 있으면 don't count
//// 확인하는 곳은 s.first+1~ e.first-1, s.second+1 ~ e.second -1
////
//
//bool  check(pair<int, int>s, pair<int, int> e) {
//	// 보석이 하나 이하이면 true 이때 보석이 하나이고 불순물이 없으면 정상적으로 나뉜것이다.
//	//보석이 여러개이면 false
//	int s_cnt = 0;
//	int d_cnt = 0;
//	for (int i = 0; i < star.size(); i++) {
//		if (s.first <= star[i].first && star[i].first <= e.first && s.second <= star[i].second && star[i].second <= e.second) {
//			s_cnt++;
//		}
//	}
//	for (int i = 0; i < dirty.size(); i++) {
//		if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second) {
//			d_cnt++;
//		}
//	}
//
//	if (s_cnt == 1 && d_cnt == 0) {
//		ans_f = true;
//		return true;
//	}
//	else if (s_cnt == 0) {
//		ans_f=false;
//		return true;
//	}
//	else {
//		ans_f = false;
//		return false;
//	}
//}
//
//
//
//void divide(pair<int, int>s, pair<int, int> e, int way)
//{
//	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" <<" way : " << way <<endl;
//	cout <<"cnt : "<< ans_cnt << endl;
//
//	if (check(s, e)) {
//		return;
//	}
//
//		// way==1 이라는 것은 전에 가로였으니 세로로 구현해라
//	if (way == 1) {
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//왼쪽
//				divide(s, { e.first ,i - 1,}, 2);
//				//오른쪽
//				divide({ s.first ,i + 1}, e, 2);
//			}
//		}
//	}
//	// way==2 이라는 것은 전에 세로였으니 가로로 구현해라
//	else if (way == 2) {
//
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				divide({ i + 1,s.second }, e, 1);
//				//위
//				divide(s, { i - 1,e.second }, 1);
//			}
//		}
//	}
//	//첫 시작 -> 가로세로 모두 가능
//	else {
//		//가로줄 검사 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				divide({ i + 1,s.second }, e, 1);
//				//위
//				divide(s, { i - 1,e.second }, 1);
//
//				if (ans_f) {
//					answer++;
//					ans_cnt = false;
//				}
//			}
//		}
//
//		ans_cnt = false;
//
//		//새로줄 검사
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//왼쪽
//				divide(s, { e.first ,i - 1}, 2);
//				//오른쪽
//				divide({ s.first ,i + 1}, e, 2);
//				//돌고 나왔을때 석판을 잘 나눴다면 answer++
//				if (ans_cnt == star.size()) {
//					answer++;
//					ans_cnt = 0;
//				}
//			}
//		}
//
//	}
//
//	return;
//}
//
//int main()
//{
//	//init
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int a;
//			cin >> a;
//			if (a == 1) {
//				dirty.push_back({ i,j });
//			}
//			else if (a == 2) {
//				star.push_back({ i,j });
//			}
//			map[i][j] = a;
//		}
//	}
//	// logic
//	// dirty에서 나눌수 있다면 나눠서 같은 로직을 반복한다.
//	// return 을 언제 해주느냐?
//	// 처음은 가로와 세로 모두 고려가 가능
//	// 그 이후부터는 이전에 자른 방향과 같은 방향으로는 자를수 없다.
//	// 모든 dirty배열에 들어있는 값들에 대해서 가로세로를 생각해주어야 하는지..
//	// 모든 index of 2_ dimension 을 돌면서 보석을 가를수있는지 판단?
//	// 가로세로는 매개변수에 boolean값을 넘겨주면서 check
//	// 혹은 불순물이 없다면 ??
//
//	divide({ 0,0 }, { n - 1,n - 1 }, 0);
//	cout << answer;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<pair<int, int>> dirty;
//vector<pair<int, int>> star;
//vector<vector<int>> map(20, vector<int>(20, 0));
//
//int n;
//bool ans_f = false;
//int ans_cnt = 0;
//int answer = 0;
///*
//8
//0 0 0 0 0 2 0 0
//0 0 0 0 0 0 1 0
//0 0 2 1 0 0 2 0
//0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0
//0 0 0 2 1 0 0 0
//0 0 0 0 0 0 2 0
//0 0 0 0 0 0 0 0
//*/
//
////star가 하나만 있을때 까지 divide ,, and => conquer
////이때 dirty가 하나라도 있으면 don't count
//// 확인하는 곳은 s.first+1~ e.first-1, s.second+1 ~ e.second -1
////
//
//bool  check(pair<int, int>s, pair<int, int> e) {
//	// 보석이 하나 이하이면 true 이때 보석이 하나이고 불순물이 없으면 정상적으로 나뉜것이다.
//	//보석이 여러개이면 false
//	int s_cnt = 0;
//	int d_cnt = 0;
//	for (int i = 0; i < star.size(); i++) {
//		if (s.first <= star[i].first && star[i].first <= e.first && s.second <= star[i].second && star[i].second <= e.second) {
//			s_cnt++;
//		}
//	}
//	for (int i = 0; i < dirty.size(); i++) {
//		if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second) {
//			d_cnt++;
//		}
//	}
//
//	if (s_cnt == 1 && d_cnt == 0) {
//		return true;
//	}
//
//	else {
//		return false;
//	}
//}
//
//
//
//int divide(pair<int, int>s, pair<int, int> e, int way)
//{
//	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" << " way : " << way << endl;
//	cout << "cnt : " << ans_cnt << endl;
//	int s_cnt = 0;
//
//	if (check(s, e)) {
//		return 1;
//	}
//	for (int i = 0; i < star.size(); i++) {
//		if (s.first <= star[i].first && star[i].first <= e.first && s.second <= star[i].second && star[i].second <= e.second) {
//			s_cnt++;
//		}
//	}
//	if (s_cnt == 0) return 0;
//
//	// way==1 이라는 것은 전에 가로였으니 세로로 구현해라
//	if (way == 1) {
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//왼쪽
//				ans_cnt += divide(s, { e.first ,i - 1, }, 2);
//				//오른쪽
//				ans_cnt += divide({ s.first ,i + 1 }, e, 2);
//			}
//		}
//	}
//	// way==2 이라는 것은 전에 세로였으니 가로로 구현해라
//	else if (way == 2) {
//
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				ans_cnt += divide({ i + 1,s.second }, e, 1);
//				//위
//				ans_cnt += divide(s, { i - 1,e.second }, 1);
//			}
//		}
//	}
//	//첫 시작 -> 가로세로 모두 가능
//	else {
//		//가로줄 검사 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				ans_cnt += divide({ i + 1,s.second }, e, 1);
//				//위
//				ans_cnt += divide(s, { i - 1,e.second }, 1);
//				int a = 0;
//				if (ans_cnt == star.size()) {
//					answer++;
//				}
//			}
//		}
//		ans_cnt = 0;
//
//		//새로줄 검사
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//왼쪽
//				ans_cnt += divide(s, { e.first ,i - 1 }, 2);
//				//오른쪽
//				ans_cnt += divide({ s.first ,i + 1 }, e, 2);
//				//돌고 나왔을때 석판을 잘 나눴다면 answer++
//				int a = 0;
//				if (ans_cnt == star.size()) {
//					answer++;
//				}
//			}
//		}
//
//	}
//
//	return 0;
//}
//
//int main()
//{
//	//init
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int a;
//			cin >> a;
//			if (a == 1) {
//				dirty.push_back({ i,j });
//			}
//			else if (a == 2) {
//				star.push_back({ i,j });
//			}
//			map[i][j] = a;
//		}
//	}
//	// logic
//	// dirty에서 나눌수 있다면 나눠서 같은 로직을 반복한다.
//	// return 을 언제 해주느냐?
//	// 처음은 가로와 세로 모두 고려가 가능
//	// 그 이후부터는 이전에 자른 방향과 같은 방향으로는 자를수 없다.
//	// 모든 dirty배열에 들어있는 값들에 대해서 가로세로를 생각해주어야 하는지..
//	// 모든 index of 2_ dimension 을 돌면서 보석을 가를수있는지 판단?
//	// 가로세로는 매개변수에 boolean값을 넘겨주면서 check
//	// 혹은 불순물이 없다면 ??
//
//	divide({ 0,0 }, { n - 1,n - 1 }, 0);
//	cout << answer;
//
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<pair<int, int>> dirty;
//vector<pair<int, int>> star;
//vector<vector<int>> map(20, vector<int>(20, 0));
//
//int n;
//bool ans_f = false;
//int ans_cnt = 0;
//int answer = 0;
///*
//8
//0 0 0 0 0 2 0 0
//0 0 0 0 0 0 1 0
//0 0 2 1 0 0 2 0
//0 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0
//0 0 0 2 1 0 0 0
//0 0 0 0 0 0 2 0
//0 0 0 0 0 0 0 0
//*/
//
////star가 하나만 있을때 까지 divide ,, and => conquer
////이때 dirty가 하나라도 있으면 don't count
//// 확인하는 곳은 s.first+1~ e.first-1, s.second+1 ~ e.second -1
//
//bool divide(pair<int, int>s, pair<int, int> e, int way)
//{
//	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" << " way : " << way << endl;
//	cout << "cnt : " << ans_cnt << endl;
//	int s_cnt = 0;
//
//	// 보석이 하나 이하이면 true 이때 보석이 하나이고 불순물이 없으면 정상적으로 나뉜것이다.
//	//보석이 여러개이면 false
//	int d_cnt = 0;
//	for (int i = 0; i < star.size(); i++) {
//		if (s.first <= star[i].first && star[i].first <= e.first && s.second <= star[i].second && star[i].second <= e.second) {
//			s_cnt++;
//		}
//	}
//	for (int i = 0; i < dirty.size(); i++) {
//		if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second) {
//			d_cnt++;
//		}
//	}
//
//	if (s_cnt == 1 && d_cnt == 0) {
//		return true;
//	}
//
//	else if (s_cnt == 1 && d_cnt > 0) {
//		return false;
//	}
//	else if (s_cnt == 0) return false;
//	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	// way==1 이라는 것은 전에 가로였으니 세로로 구현해라
//	if (way == 1) {
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.first <= star[j].first && e.first >= star[j].first && i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//
//				if (divide(s, { e.first ,i - 1, }, 2) == true && divide({ s.first ,i + 1 }, e, 2) == true)
//					return true;
//
//			}
//		}
//	}
//	// way==2 이라는 것은 전에 세로였으니 가로로 구현해라
//	else if (way == 2) {
//
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.second <= star[j].second && e.second >= star[j].second && i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				if (divide(s, { i - 1,e.second }, 1) == true && divide({ i + 1,s.second }, e, 1) == true) {
//					return true;
//				}
//				//위
//			}
//		}
//	}
//	//첫 시작 -> 가로세로 모두 가능
//	else {
//		//가로줄 검사 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.second <= star[j].second && e.second >= star[j].second && i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//아래
//				if (divide({ i + 1,s.second }, e, 1) == true && divide(s, { i - 1,e.second }, 1) == true) {
//					answer++;
//				}
//				//위
//
//			}
//		}
//		ans_cnt = 0;
//
//		//새로줄 검사
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.first <= star[j].first && e.first >= star[j].first && i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//왼쪽
//				if (divide(s, { e.first ,i - 1 }, 2) == true && divide({ s.first ,i + 1 }, e, 2) == true) {
//					answer++;
//				}
//
//			}
//		}
//
//	}
//
//	return 0;
//}
//
//int main()
//{
//	//init
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int a;
//			cin >> a;
//			if (a == 1) {
//				dirty.push_back({ i,j });
//			}
//			else if (a == 2) {
//				star.push_back({ i,j });
//			}
//			map[i][j] = a;
//		}
//	}
//	// logic
//	// dirty에서 나눌수 있다면 나눠서 같은 로직을 반복한다.
//	// return 을 언제 해주느냐?
//	// 처음은 가로와 세로 모두 고려가 가능
//	// 그 이후부터는 이전에 자른 방향과 같은 방향으로는 자를수 없다.
//	// 모든 dirty배열에 들어있는 값들에 대해서 가로세로를 생각해주어야 하는지..
//	// 모든 index of 2_ dimension 을 돌면서 보석을 가를수있는지 판단?
//	// 가로세로는 매개변수에 boolean값을 넘겨주면서 check
//	// 혹은 불순물이 없다면 ??
//
//
//	//예외처리
//	if (n == 1) {
//		cout << 1;
//	}
//	if (n == 2) {
//		if (star.size() >= 3) {
//			cout << -1;
//			return 0;
//		}
//		else if (star.size() == 1) {
//			cout << 2;
//			return 0;
//		}
//		else {
//			if (star[0].first != star[1].first && star[0].second != star[1].second) {
//				cout << -1;
//				return 0;
//			}
//			else cout << 1;
//			return 0;
//		}
//	}
//
//
//	divide({ 0,0 }, { n - 1,n - 1 }, 0);
//	if (answer != 0)cout << answer;
//	else cout << -1;
//
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> dirty;
vector<pair<int, int>> star;
vector<vector<int>> map(20, vector<int>(20, 0));

int n;
bool ans_f = false;
int ans_cnt = 0;
int answer = 0;
/*
8
0 0 0 0 0 2 0 0
0 0 0 0 0 0 1 0
0 0 2 1 0 0 2 0
0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 2 1 0 0 0
0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0
*/

//star가 하나만 있을때 까지 divide ,, and => conquer
//이때 dirty가 하나라도 있으면 don't count
// 확인하는 곳은 s.first+1~ e.first-1, s.second+1 ~ e.second -1

bool divide(pair<int, int>s, pair<int, int> e, int way)
{
	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" << " way : " << way << endl;
	cout << "cnt : " << ans_cnt << endl;
	int s_cnt = 0;

	// 보석이 하나 이하이면 true 이때 보석이 하나이고 불순물이 없으면 정상적으로 나뉜것이다.
	//보석이 여러개이면 false
	int d_cnt = 0;
	for (int i = 0; i < star.size(); i++) {
		if (s.first <= star[i].first && star[i].first <= e.first && s.second <= star[i].second && star[i].second <= e.second) {
			s_cnt++;
		}
	}
	for (int i = 0; i < dirty.size(); i++) {
		if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second) {
			d_cnt++;
		}
	}

	if (s_cnt == 1 && d_cnt == 0) {
		return true;
	}

	else if (s_cnt == 1 && d_cnt > 0) {
		return false;
	}
	else if (s_cnt == 0) return false;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// way==1 이라는 것은 전에 가로였으니 세로로 구현해라
	if (way == 1) {
		for (int i = 0 ; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second&& s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].second==star[j].second) {
					f = false;
					continue;
				}
			}
			if (f) {

				if (divide(s, { e.first ,dirty[i].second - 1, }, 2) == true && divide({ s.first ,dirty[i].second + 1 }, e, 2) == true)
					return true;

			}
		}
	}
	// way==2 이라는 것은 전에 세로였으니 가로로 구현해라
	else if (way == 2) {

		for (int i = 0; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second && s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].first == star[j].first) {
					f = false;
					continue;
				}
			}
			if (f) {
				//아래
				if (divide(s, { dirty[i].first - 1,e.second }, 1) == true && divide({ dirty[i].first + 1,s.second }, e, 1) == true) {
					return true;
				}
				//위
			}
		}
	}
	//첫 시작 -> 가로세로 모두 가능
	else {
		//가로줄 검사 
		for (int i = 0; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second && s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].first == star[j].first) {
					f = false;
					continue;
				}
			}
			if (f) {
				//아래
				if (divide({ dirty[i].first + 1,s.second }, e, 1	) == true && divide(s, { dirty[i].first - 1,e.second }, 1) == true) {
					answer++;
				}
				//위

			}
		}
		ans_cnt = 0;

		//새로줄 검사
		for (int i =0; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second && s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].second == star[j].second) {
					f = false;
					continue;
				}
			}
			if (f) {
				//왼쪽
				if (divide(s, { e.first ,dirty[i].second - 1 }, 2) == true && divide({ s.first ,dirty[i].second + 1 }, e, 2) == true) {
					answer++;
				}

			}
		}

	}

	return 0;
}

int main()
{
	//init
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				dirty.push_back({ i,j });
			}
			else if (a == 2) {
				star.push_back({ i,j });
			}
			map[i][j] = a;
		}
	}
	// logic
	// dirty에서 나눌수 있다면 나눠서 같은 로직을 반복한다.
	// return 을 언제 해주느냐?
	// 처음은 가로와 세로 모두 고려가 가능
	// 그 이후부터는 이전에 자른 방향과 같은 방향으로는 자를수 없다.
	// 모든 dirty배열에 들어있는 값들에 대해서 가로세로를 생각해주어야 하는지..
	// 모든 index of 2_ dimension 을 돌면서 보석을 가를수있는지 판단?
	// 가로세로는 매개변수에 boolean값을 넘겨주면서 check
	// 혹은 불순물이 없다면 ??


	//예외처리
	if (n == 1) {
		cout << 1;
	}
	if (n == 2) {
		if (star.size() >= 3) {
			cout << -1;
			return 0;
		}
		else if (star.size() == 1) {
			cout << 2;
			return 0;
		}
		else {
			if (star[0].first != star[1].first && star[0].second != star[1].second) {
				cout << -1;
				return 0;
			}
			else cout << 1;
			return 0;
		}
	}


	divide({ 0,0 }, { n - 1,n - 1 }, 0);
	if (answer != 0)cout << answer;
	else cout << -1;

	return 0;
}

/*
0 0 0 0 0 2 0 0 0 0 0 0 0 2 0 0 0 0 0 2 
0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0  
0 0 2 1 0 0 2 0 0 0 2 1 0 0 2 0 0 0 2 1 
0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 2 1 0 0 0 0 0 0 2 1 0 0 0 0 0 0 2 
0 0 0 0 0 2 0 0 0 0 0 0 0 2 0 0 0 0 0 2
0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 2 1 0 0 2 0 0 0 2 1 0 0 2 0 0 0 2 1
0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 2 1 0 0 0 0 0 0 2 1 0 0 0 0 0 0 2
0 0 0 0 0 2 0 0 0 0 0 0 0 2 0 0 0 0 0 2
0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 2 1 0 0 2 0 0 0 2 1 0 0 2 0 0 0 2 1
0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 2 1 0 0 0 0 0 0 2 1 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 2 1 0 0 0 0 0 0 2 1 0 0 0 0 0 0 2
*/