#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;
/*

1 4  
2 3 
3 2  
4 1 
5 5 

1 4
2 5
3 6
4 2
5 7
6 1
7 3

*/
/*
int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		//init
		int n = 0;
		cin >> n;
		int answer = n;
		stack <int> s;
		vector<pair<int, int>>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i].first >> vec[i].second;
		}
		//logic
		sort(vec.begin(), vec.end(),greater<pair<int,int>>());
		int cnt = 0;
		for (int i = 0; i < vec.size(); i++) {
			while (!s.empty()&&vec[i].second<s.top()) {
				s.pop();
			}
			s.push(vec[i].second);
		}
		cout << s.size();
	}
	return 0;
}*/

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		//init
		int n = 0;
		cin >> n;
		int answer = n;
		vector<pair<int, int>>vec(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i].first >> vec[i].second;
		}
		//logic
		sort(vec.begin(), vec.end());
		int tmp = vec[0].second;
		for (int i = 1; i < vec.size(); i++) {
			if (vec[i].second < tmp) {
				tmp = vec[i].second;
				answer++;
			}
		}
		cout << answer+1 << endl;
	}
	return 0;
}