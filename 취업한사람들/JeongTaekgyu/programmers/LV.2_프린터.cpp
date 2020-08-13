#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue <pair <int, int>> Que;// 중요도 queue 와 index가 있는 queue 의 pair
	priority_queue<int> Pque;	// 우선순위 큐는 알아서 정렬해준다.  default는 less 큐 (내림차순)
	int answer = 0;
	int rank = 0;	// 몇 번째로 출력되는지 알려주는 값

	for (int i = 0; i < priorities.size(); i++)
	{
		Que.push(make_pair(priorities[i], i));
		Pque.push(priorities[i]);
	}

	while (1)
	{
		if (Que.front().first == Pque.top())	// 중요도 큐의 첫번째 값과 우선순위 큐의 첫번째 값이 같으면
		{
			rank++;	// 출력할 거니까 rank 값(몇 번째로 출력되는지 알려줌)을 증가
			Pque.pop();

			if (location == Que.front().second)
			{
				answer = rank;
				break;
			}
			else {
				Que.pop();
			}
		}
		else {
			Que.push(Que.front());
			Que.pop();
		}
	}

	return answer;
}

int main()
{
	vector<int> priorities;
	int location;
	int size;
	int temp;

	cin >> size;
	cin >> location;

	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		priorities.push_back(temp);
	}
	
	cout << solution(priorities, location) << endl;
	
	return 0;
}