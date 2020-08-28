#include<iostream>
#include <string>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;
vector<string> user;
vector<string> ban;
string r_tmp;
string tmp;
set<string> c_set;
vector<bool>check(10, false);
int answer;
void dfs(int idx, int cnt) {
	if (ban.size() == cnt) {
		r_tmp = tmp;
		sort(r_tmp.begin(), r_tmp.end());
		c_set.insert(r_tmp);
		answer++;
		return;
	}

	for (int i = 0; i < user.size(); i++) {
		bool f = true;
		if (check[i] == true) continue;

		//if each length is same
		if (user[i].size() == ban[idx].size()) {
			for (int j = 0; j < user[i].size(); j++) {
				if (ban[idx][j] != '*' && user[i][j] != ban[idx][j]) {
					f = false;
					break;
				}
			}
			if (f) {
				check[i] = true;
				tmp.push_back(i);
				dfs(idx + 1, cnt + 1);
				tmp.pop_back();
				check[i] = false;

			}
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	user = user_id;
	ban = banned_id;
	dfs(0, 0);
	cout << c_set.size();

	return answer;
}

int main() {
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" });
	return 0;
}
