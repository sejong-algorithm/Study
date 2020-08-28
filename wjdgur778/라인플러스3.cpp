#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int cnt = 0;
int ans = 0;
int pre = 0;
string road;
int n = 0;
int result = 0;
bool f = true;
queue <int> q;
int check(int i) {
	int index = i + 1;

	if (road[index] == '1') {
		while (road[index] == '1') {
			ans++;
			index++;
		}
	}
	return index;

}
int main()
{
	cin >> road;
	int i = 0;
	while (i < road.size()) {
		if (road[i] == '0' && cnt != 3) {
			if (q.empty())pre = i;
			q.push(i);
			cnt++;
			ans++;
		}
		else {
			ans++;
		}

		if (cnt == 3) {

			i = check(i) - 1;
			result = max(result, ans);
			if (f) ans -= (q.front() + 1);
			else { ans -= (q.front() - pre); }
			pre = q.front();
			q.pop();
			cnt--;
			f = false;
		}
		i++;
	}
	result = max(result, ans);
	cout << result;

	return 0;
}