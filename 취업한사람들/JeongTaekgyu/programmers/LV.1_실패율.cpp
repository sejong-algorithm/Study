#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<double> fail_rate;
	int stage_total = 0;
	int stage_cnt;
	double temp;
	int temp2;

	for (int i = 1; i <= N; i++)
	{
		stage_total = 0;
		stage_cnt = 0;
		for (int j = 0; j < stages.size(); j++)
		{
			if (i <= stages[j])
			{
				stage_total++;
				if (i == stages[j])
					stage_cnt++;
			}
		}
		fail_rate.push_back((double)stage_cnt / stage_total);
	}

	for (int i = 0; i < N; i++)
		answer.push_back(i+1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (fail_rate[j] < fail_rate[j + 1])
			{
				temp = fail_rate[j];
				fail_rate[j] = fail_rate[j + 1];
				fail_rate[j + 1] = temp;

				temp2 = answer[j];
				answer[j] = answer[j + 1];
				answer[j + 1] = temp2;
			}
		}
	}

	return answer;
}
int main()
{
	int n, temp;
	int stages_length;
	vector<int> stages;

	cin >> n;
	cin >> stages_length;

	for (int i = 0; i < stages_length; i++)
	{
		cin >> temp;
		stages.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		cout << solution(n, stages)[i];
	}

	return 0;
}