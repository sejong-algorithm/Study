#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solution(vector<vector<int>> t) {
	int answer = 0;
	int sum = t[0][0];

	for (int i = t.size() - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			t[i-1][j] +=max(t[i][j], t[i][j + 1]);
		}
	}
	cout << t[0][0];
	return 0;
}
int main() {

	solution({ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} });

	return 0;
}