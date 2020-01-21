#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;
	int day;
	int cnt;
	int max;
	int complete;
	int size;
	
	size = progresses.size();

	for(int i = 0; i < size; i++)
		days.push_back(0);

	// 각 작업의 완료된 날짜를 세준다
	day = 0;
	cnt = 0;
	while (1)
	{
		day++;
		for (int i = 0; i < size; i++)
		{
			complete = progresses[i] + (speeds[i] * day);
			if (complete >= 100 && days[i] == 0)
			{
				days[i] = day;
				cnt++;
			}
			if (cnt == size)
				break;
		}
		if (cnt == size)
			break;
	}

	// 남은 작업
	cnt = 0;
	max = days[0];
	for (int i = 0; i < size; i++)
	{
		if (max >= days[i]) {
			cnt++;
		}
		else {
			answer.push_back(cnt);
			cnt = 1;
			max = days[i];
		}

		if (i == size - 1)
			answer.push_back(cnt);
	}

	return answer;
}

int main()
{
	vector<int> progresses;
	vector<int> speeds;
	vector<int> answer;
	int size;
	int temp;
	int i;

	cin >> size;

	for (i = 0; i < size; i++)
	{
		cin >> temp;
		progresses.push_back(temp);
	}

	for (i = 0; i < size; i++)
	{
		cin >> temp;
		speeds.push_back(temp);
	}

	cout << endl;

	// 이거 solution 함수에 있는 반환 값이 vector 인데 그 vector(여기선 answer)의 크기는 아래처럼 알면 되는거겠지?
	for (i = 0; i < solution(progresses, speeds).size(); i++)
		cout << solution(progresses, speeds)[i] << " ";

	return 0;
}