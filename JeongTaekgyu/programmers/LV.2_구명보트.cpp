#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	
	// 최대 2명까지 탈 수 있다는걸 생각하면 쉬워 진다.

	sort(people.begin(), people.end());// default는 오름차순 (less<자료형>())

	if (people.size() == 1)
		return answer = 1;
	// people.size() >= 2 부터
	for (int i = 1, j = 0; i <= people.size() - j; i++)	// i = 1부터 하기 때문에
	{
		// 구명 보트 무게보다 2명의 무게가 더 나가면 2명중 더 무거운 사람은 혼자서 구명보트를 타야한다.
		if (people[j] + people[people.size() - i] > limit)
		{
			answer++;
		}
		else {
			j++;
			answer++;
		}
	}

	return answer;
}
int main()
{
	vector<int> people;
	int n;
	int temp;
	int limit;

	cin >> n;
	cin >> limit;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		people.push_back(temp);
	}

	cout << solution(people, limit) << endl;

	return 0;
}