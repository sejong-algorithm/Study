#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> stair;
int answer = 0;
//������ ����� on/off system���� ����

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		stair.push_back({ a,a });
	}
	stair.push_back({ 0,0 });
	if (n == 1) {
		cout << stair[0].first;
	}
	else if (n == 2) {
		cout << stair[0].first + stair[1].first;
	}
	else if (n == 3) {
		cout << max(stair[0].first + stair[2].first, stair[1].first + stair[2].first);
	}
	else {
		//�������� ���� �ִ��� ������
		
		for (int i = n - 4; i >= 0; i--) {
			stair[i].second += max(stair[i + 2].first, stair[i + 2].second);
			stair[i].first += stair[i + 1].second;
		}
		cout << max(max(stair[0].first, stair[0].second), max(stair[1].first, stair[1].second)) + stair[n - 1].first;

	}
	return 0;
}