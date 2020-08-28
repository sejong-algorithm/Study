#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n;

vector<vector<int>> map;
vector<vector<int>> c_map(500, vector<int>(500, -1));

int dfs(int x, int y) {
	if (x == n - 1) {

		return  map[x][y];
	}

	if (c_map[x ][y] != -1) {

		return c_map[x][y];
	}
	
		return c_map[x][y] = max(dfs(x + 1, y + 1), dfs(x + 1, y)) + map[x][y];

}

int solution(vector<vector<int>> t) {

	map = t;

	int answer = 0;

	n = t.size();

	cout<< dfs(0, 0);
	return answer;

}

int main() {

		solution({ 
			{1},
			{1,1},
			{1,1,1},
			{1,1,1,1},
			{0,0,0,0,0} ,
			{1,4,3,2,1,2},
			{9,6,7,5,4,3,2}
			});


		return 0;

}