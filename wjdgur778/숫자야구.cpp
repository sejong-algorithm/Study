#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector <vector <int>> v;
int cnt = 0;
//경우의 수만큼 돌린다
//0 인 경우 비교  true  -> 비교했던 baseball 요소를 푸쉬
//strike 와 ball 에 따른 경우의 수를 어떻게 찾는가가 포인트일것
//s와 b 의 모든 경우의 수를 작성해야하는가? 일반화를 시킬수 있을까?


bool check(string arr1, string arr2, int s, int b) {
	int new_s = 0;
	int new_b = 0;

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {

			if (i == j) {
				if (arr1[i] == arr2[j]) {
					new_s++;
				}
			}
			else {
				if (arr1[i] == arr2[j]) {
					new_b++;
				}
			}

		}
	}

	if (new_s == s && new_b == b) {
		return true;
	}
	else {
		return false;
	}
}

bool possible(int a) {
	string s = to_string(a);
	
	for (int i = 0;i < 2;i++) {
		for (int j = i + 1; j < 3;j++) {
			if (s[i] != '0' && s[j] != '0') {
				if (s[i] == s[j]) {
					return false;
				}
			}
			else return false;
		}
	}
	return true;
}




int main() {
	int n;
	int b;
	cin >> n;

	for (int i = 0;i < n;i++) {
		vector<int >a;

		for (int j = 0;j < 3;j++) {
			cin >> b;
			a.push_back(b);
		}
		v.push_back(a);
	}

	/*
123,1,1
356,1,0
327,2,0
489,0,1
*/
	int j = 0;

	for (int i = 123;i <= 987;i++) {
		if (possible(i)) {

			while (j < v.size() && check(to_string(v[j][0]), to_string(i), v[j][1], v[j][2])) {
				j++;
			}

			if (j == v.size()) {
				cnt++;
				cout << to_string(i) << endl;
			}
			j = 0;
		}

	}
	cout << cnt;

	return 0;
}