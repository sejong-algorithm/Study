#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, k;
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p_q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;

// 5  to 17
int main() {
	cin >> n >> k;
	int cnt = 0;
	bool f = false;
	int answer = 0;
	
	vector<bool>check(200001, false);
	if (n >= k) {
		cout<< n - k; 
		return 0;
	}
	p_q.push(make_pair(0, n));
	check[n] = true;

	while (!p_q.empty()) {

			int front = p_q.top().second;
			int way = p_q.top().first;
			p_q.pop();

			if (front== k) {
				answer =way;
				break;
			}
			//cout << "front : " << front << endl;
			if (front * 2 <=100000)
				if (!check[front * 2]) {
					{
						check[front *2] = true;
						p_q.push(make_pair(way, front * 2));
					}
				}
			if (front + 1 <= 100000) {
				if (!check[front + 1]) {
					check[front + 1] = true;
					p_q.push(make_pair(way + 1, front + 1));
				}
			}
			if (front - 1 >= 0) {
				if (!check[front - 1]) {
					check[front - 1] = true;
					p_q.push(make_pair(way + 1, front - 1));
				}
			
		}
		//cout << endl;
	}

	 cout << answer;
	return 0;
}
