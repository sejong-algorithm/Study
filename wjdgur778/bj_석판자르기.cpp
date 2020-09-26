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
////star�� �ϳ��� ������ ���� divide ,, and => conquer
////�̶� dirty�� �ϳ��� ������ don't count
//// Ȯ���ϴ� ���� s.first+1~ e.first-1, s.second+1 ~ e.second -1
////
//
//bool  check(pair<int, int>s, pair<int, int> e) {
//	// ������ �ϳ� �����̸� true �̶� ������ �ϳ��̰� �Ҽ����� ������ ���������� �������̴�.
//	//������ �������̸� false
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
//		// way==1 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//				//����
//				divide(s, { e.first ,i - 1,}, 2);
//				//������
//				divide({ s.first ,i + 1}, e, 2);
//			}
//		}
//	}
//	// way==2 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//				//�Ʒ�
//				divide({ i + 1,s.second }, e, 1);
//				//��
//				divide(s, { i - 1,e.second }, 1);
//			}
//		}
//	}
//	//ù ���� -> ���μ��� ��� ����
//	else {
//		//������ �˻� 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//�Ʒ�
//				divide({ i + 1,s.second }, e, 1);
//				//��
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
//		//������ �˻�
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//����
//				divide(s, { e.first ,i - 1}, 2);
//				//������
//				divide({ s.first ,i + 1}, e, 2);
//				//���� �������� ������ �� �����ٸ� answer++
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
//	// dirty���� ������ �ִٸ� ������ ���� ������ �ݺ��Ѵ�.
//	// return �� ���� ���ִ���?
//	// ó���� ���ο� ���� ��� ����� ����
//	// �� ���ĺ��ʹ� ������ �ڸ� ����� ���� �������δ� �ڸ��� ����.
//	// ��� dirty�迭�� ����ִ� ���鿡 ���ؼ� ���μ��θ� �������־�� �ϴ���..
//	// ��� index of 2_ dimension �� ���鼭 ������ �������ִ��� �Ǵ�?
//	// ���μ��δ� �Ű������� boolean���� �Ѱ��ָ鼭 check
//	// Ȥ�� �Ҽ����� ���ٸ� ??
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
////star�� �ϳ��� ������ ���� divide ,, and => conquer
////�̶� dirty�� �ϳ��� ������ don't count
//// Ȯ���ϴ� ���� s.first+1~ e.first-1, s.second+1 ~ e.second -1
////
//
//bool  check(pair<int, int>s, pair<int, int> e) {
//	// ������ �ϳ� �����̸� true �̶� ������ �ϳ��̰� �Ҽ����� ������ ���������� �������̴�.
//	//������ �������̸� false
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
//	// way==1 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//				//����
//				ans_cnt += divide(s, { e.first ,i - 1, }, 2);
//				//������
//				ans_cnt += divide({ s.first ,i + 1 }, e, 2);
//			}
//		}
//	}
//	// way==2 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//				//�Ʒ�
//				ans_cnt += divide({ i + 1,s.second }, e, 1);
//				//��
//				ans_cnt += divide(s, { i - 1,e.second }, 1);
//			}
//		}
//	}
//	//ù ���� -> ���μ��� ��� ����
//	else {
//		//������ �˻� 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//�Ʒ�
//				ans_cnt += divide({ i + 1,s.second }, e, 1);
//				//��
//				ans_cnt += divide(s, { i - 1,e.second }, 1);
//				int a = 0;
//				if (ans_cnt == star.size()) {
//					answer++;
//				}
//			}
//		}
//		ans_cnt = 0;
//
//		//������ �˻�
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//����
//				ans_cnt += divide(s, { e.first ,i - 1 }, 2);
//				//������
//				ans_cnt += divide({ s.first ,i + 1 }, e, 2);
//				//���� �������� ������ �� �����ٸ� answer++
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
//	// dirty���� ������ �ִٸ� ������ ���� ������ �ݺ��Ѵ�.
//	// return �� ���� ���ִ���?
//	// ó���� ���ο� ���� ��� ����� ����
//	// �� ���ĺ��ʹ� ������ �ڸ� ����� ���� �������δ� �ڸ��� ����.
//	// ��� dirty�迭�� ����ִ� ���鿡 ���ؼ� ���μ��θ� �������־�� �ϴ���..
//	// ��� index of 2_ dimension �� ���鼭 ������ �������ִ��� �Ǵ�?
//	// ���μ��δ� �Ű������� boolean���� �Ѱ��ָ鼭 check
//	// Ȥ�� �Ҽ����� ���ٸ� ??
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
////star�� �ϳ��� ������ ���� divide ,, and => conquer
////�̶� dirty�� �ϳ��� ������ don't count
//// Ȯ���ϴ� ���� s.first+1~ e.first-1, s.second+1 ~ e.second -1
//
//bool divide(pair<int, int>s, pair<int, int> e, int way)
//{
//	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" << " way : " << way << endl;
//	cout << "cnt : " << ans_cnt << endl;
//	int s_cnt = 0;
//
//	// ������ �ϳ� �����̸� true �̶� ������ �ϳ��̰� �Ҽ����� ������ ���������� �������̴�.
//	//������ �������̸� false
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
//	// way==1 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//	// way==2 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
//				//�Ʒ�
//				if (divide(s, { i - 1,e.second }, 1) == true && divide({ i + 1,s.second }, e, 1) == true) {
//					return true;
//				}
//				//��
//			}
//		}
//	}
//	//ù ���� -> ���μ��� ��� ����
//	else {
//		//������ �˻� 
//		for (int i = s.first + 1; i <= e.first - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.second <= star[j].second && e.second >= star[j].second && i == star[j].first) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//�Ʒ�
//				if (divide({ i + 1,s.second }, e, 1) == true && divide(s, { i - 1,e.second }, 1) == true) {
//					answer++;
//				}
//				//��
//
//			}
//		}
//		ans_cnt = 0;
//
//		//������ �˻�
//		for (int i = s.second + 1; i <= e.second - 1; i++) {
//			bool f = true;
//			for (int j = 0; j < star.size(); j++) {
//				if (s.first <= star[j].first && e.first >= star[j].first && i == star[j].second) {
//					f = false;
//					continue;
//				}
//			}
//			if (f) {
//				//����
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
//	// dirty���� ������ �ִٸ� ������ ���� ������ �ݺ��Ѵ�.
//	// return �� ���� ���ִ���?
//	// ó���� ���ο� ���� ��� ����� ����
//	// �� ���ĺ��ʹ� ������ �ڸ� ����� ���� �������δ� �ڸ��� ����.
//	// ��� dirty�迭�� ����ִ� ���鿡 ���ؼ� ���μ��θ� �������־�� �ϴ���..
//	// ��� index of 2_ dimension �� ���鼭 ������ �������ִ��� �Ǵ�?
//	// ���μ��δ� �Ű������� boolean���� �Ѱ��ָ鼭 check
//	// Ȥ�� �Ҽ����� ���ٸ� ??
//
//
//	//����ó��
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

//star�� �ϳ��� ������ ���� divide ,, and => conquer
//�̶� dirty�� �ϳ��� ������ don't count
// Ȯ���ϴ� ���� s.first+1~ e.first-1, s.second+1 ~ e.second -1

bool divide(pair<int, int>s, pair<int, int> e, int way)
{
	cout << "(" << s.first << "," << s.second << ")" << " " << "(" << e.first << "," << e.second << ")" << " way : " << way << endl;
	cout << "cnt : " << ans_cnt << endl;
	int s_cnt = 0;

	// ������ �ϳ� �����̸� true �̶� ������ �ϳ��̰� �Ҽ����� ������ ���������� �������̴�.
	//������ �������̸� false
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

	// way==1 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
	// way==2 �̶�� ���� ���� ���ο����� ���η� �����ض�
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
				//�Ʒ�
				if (divide(s, { dirty[i].first - 1,e.second }, 1) == true && divide({ dirty[i].first + 1,s.second }, e, 1) == true) {
					return true;
				}
				//��
			}
		}
	}
	//ù ���� -> ���μ��� ��� ����
	else {
		//������ �˻� 
		for (int i = 0; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second && s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].first == star[j].first) {
					f = false;
					continue;
				}
			}
			if (f) {
				//�Ʒ�
				if (divide({ dirty[i].first + 1,s.second }, e, 1	) == true && divide(s, { dirty[i].first - 1,e.second }, 1) == true) {
					answer++;
				}
				//��

			}
		}
		ans_cnt = 0;

		//������ �˻�
		for (int i =0; i <dirty.size(); i++) {
			bool f = true;
			for (int j = 0; j < star.size(); j++) {
				if (s.first <= dirty[i].first && dirty[i].first <= e.first && s.second <= dirty[i].second && dirty[i].second <= e.second && s.first <= star[j].first && star[j].first <= e.first && s.second <= star[j].second && star[j].second <= e.second && dirty[i].second == star[j].second) {
					f = false;
					continue;
				}
			}
			if (f) {
				//����
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
	// dirty���� ������ �ִٸ� ������ ���� ������ �ݺ��Ѵ�.
	// return �� ���� ���ִ���?
	// ó���� ���ο� ���� ��� ����� ����
	// �� ���ĺ��ʹ� ������ �ڸ� ����� ���� �������δ� �ڸ��� ����.
	// ��� dirty�迭�� ����ִ� ���鿡 ���ؼ� ���μ��θ� �������־�� �ϴ���..
	// ��� index of 2_ dimension �� ���鼭 ������ �������ִ��� �Ǵ�?
	// ���μ��δ� �Ű������� boolean���� �Ѱ��ָ鼭 check
	// Ȥ�� �Ҽ����� ���ٸ� ??


	//����ó��
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