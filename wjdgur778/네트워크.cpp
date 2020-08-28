#include<iostream>
#include<vector>
using namespace std;
int tn;
int cnt = 0;
vector<vector<int>> map;
vector<bool> check(200,false);

//{ 1,0,0,0,0,0,0,0 },
//{ 0,1,0,0,0,0,0,0 },
//{ 1,0,1,0,0,0,0,0 },
//{ 0,0,0,1,0,0,0,0 },
//{ 0,1,0,0,1,0,0,0 },
//{ 1,0,0,0,1,1,0,0 },
//{ 0,0,1,0,0,0,1,0 },
//{ 0,0,0,0,0,0,1,1 }
//   map  => tmp !!
void dfs(int index) {
	check[index] = true;
	for (int i = 0; i < map[index].size(); i++) {
		if (check[map[index][i]] == false) {
			dfs(map[index][i]);
		}
	}
	return;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector <vector<int>> tmp(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && computers[i][j] == 1) {
				tmp[i].push_back(j);
			}
		}
	}	
	map = tmp;


	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	return 0;
}

int main() {

	solution(5, {
		{1,0,1,0,0},
		{0,1,0,0,0},
		{1,0,1,0,1},
		{0,0,0,1,0},
		{0,0,1,0,1}
		});
	cout << cnt;


	return 0;
}