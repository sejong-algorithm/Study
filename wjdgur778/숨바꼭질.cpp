#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
int answer = 0;
vector<bool> check(100001,false);

int min(int a, int b) {

	if (a <= b) {
		return a;
	}
	else return b;

}

int main() {

	int n = 0;
	int k = 0;
	int cnt = 0;
	bool f = false;

	queue <int> q;
	cin >> n >> k; 
	if (n == k) {
		cout << 0;
		return 0;
	}
	else if (n > k) {
		cout << n - k;
		return 0;
	}
	else {
		q.push(k);
		check[k] = true;
		int tmp = -1;
		while (!q.empty()) {
			answer++;
			int size = q.size();

			for (int i = 0; i < size; i++) {
				tmp = q.front();
				q.pop();

				if (tmp % 2 == 0){
					if (tmp / 2 == n || tmp - 1 == n || tmp + 1 == n) {
						f = true;
						break;
					}
					if (tmp/2>=0&&check[tmp / 2] == false) {
						q.push(tmp / 2);
						check[tmp / 2] = true;
					}
					if (tmp-1>=0&&check[tmp - 1] == false) {
						q.push(tmp - 1);
						check[tmp - 1] = true;
					}
					if (check[tmp + 1] == false) {
						q.push(tmp + 1);
						check[tmp + 1] = true;
					}
				}

				else {
					if (tmp - 1 == n || tmp + 1 == n) {
						f = true;
						break;
					}
					if (tmp - 1 >= 0 && check[tmp - 1] == false) {
						q.push(tmp - 1);
						check[tmp - 1] = true;
					}
					if (check[tmp + 1] == false) {
						q.push(tmp + 1);
						check[tmp + 1] = true;
					}
				}
			}
			if (f)break;
		}
	}
	cout << answer;

	return 0;
}
