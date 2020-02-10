#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
	return a > b;
}
int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), desc);

	/*
	경우의 수를 따지면
	case 1. citations.size() == 1 이면서 citation[0] >= 1 인경우
	case 2. citations.size() == 1 이면서 citation[0] == 0 인경우
	case 3. citations.size() >= 2 이면서 citation의 각 값이 모두 0인경우
	case 4. citations.size() >= 2 이면서 citation의 각 값이 모두 i(인덱스)보다 큰 경우
	case 5. 그 외
	*/

	// case 1. 처리
	if (citations.size() == 1 && citations[0] >= 1)
	{
		answer = 1;
		return answer;
	}

	for (int i = 0; i < citations.size(); i++)
	{
		// case 2.3.5 처리  i = 0 , citations[0] = 0 이면 answer = 0 됨
		if (i >= citations[i])
		{
			answer = i;
			break;
		}
		// case 4. 처리
		if (i == citations.size() - 1)
		{
			answer = i+1;
			break;
		}
	}

	return answer;
}
int main()
{
	vector<int> citations;
	int temp;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		citations.push_back(temp);
	}

	cout << solution(citations) << endl;

	return 0;
}