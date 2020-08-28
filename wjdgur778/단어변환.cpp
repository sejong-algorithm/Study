#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

string start;
string target;
vector<string> words;
vector<int> check(50, 0);
int answer = 50;
void dfs(int n, int m, string s) {

	if (s == target) {
		answer = min(answer, m);
		return;
	}

	for (int i = 0; i < words.size(); i++) {
		int size = words[i].size();
		int cnt = 0;

		if (check[i] == false) {

			for (int j = 0; j < size; j++) {
				if (s[j] != words[i][j]) {
					cnt++;
				}
			}

			if (cnt == 1) {
				check[i] = true;
				dfs(i, m + 1, words[i]);
				check[i] = false;
			}
		}
	}
}

int solution(string b, string t, vector<string> w) {
	bool f = false;
	words = w;
	target = t;
	for (int i = 0; i < words.size(); i++) {
		if (target == words[i]) {
			f = true;
		}
	}
	if (f) {
		dfs(0, 0, b);
	}
	else return 0;

	return answer;
}

int main() {

	cout << solution("hit", "cog", { "hot" ,"dot","dog", "lot","log","cog" });
	return 0;
}

