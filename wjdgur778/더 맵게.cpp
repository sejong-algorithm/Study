#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

priority_queue <int,vector<int>> q;

int solution() {


	return 0;
}


int main() {

	vector<int> hot;
	int K;
	for (int i = 0; i < 6; i++) {
		int a;
		cin >> a;
		hot.push_back(a);
	}
	cin >> K;

    int answer = 0;
    int cnt = 0;
    int new_hot = 0;

    sort(hot.begin(), hot.end());

    for (int i = 0; i < hot.size() - 1; i++) {
        cnt++;
        new_hot = (*hot.begin()) + (*(hot.begin() + 1) * 2);
        if (new_hot >= K) {
            cout << cnt;
            break;
        }
        hot.begin() = (hot.begin() + 1);
        hot[0] = new_hot;
    }
    cout << cnt;
	return 0;
}
