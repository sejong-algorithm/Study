#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visit[200];

void dfs(int start, vector<vector<int>> &computers, int n) 
{
	visit[start] = 1;

	for (int i = 0; i < n; i++)
	{
		if (visit[i] != 1 && computers[start][i] == 1)
			dfs(i, computers, n);
	}

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (visit[i] != 1)
		{
			answer++;
			dfs(i, computers, n);
		}
	}

	return answer;
}
int main()
{
	vector<vector<int>> computers;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		vector<int> v_tmp;
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			v_tmp.push_back(tmp);
		}
		computers.push_back(v_tmp);
	}
	
	cout << solution(n, computers) << endl;

	return 0;
}

/*	
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		cout << computers[i][j] << " ";
	cout << endl;
}
*/