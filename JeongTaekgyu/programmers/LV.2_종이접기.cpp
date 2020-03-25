#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	int cnt;	// n번 접었을때 접은 부분의 개수

	// 접어보니까 규칙이 n번째 접은 곳의 가운데는 무조건 0이고
	// 가운데를 기준으로 대칭이다.
	// 그러므로 최소 1번은 접어야 하므로 최소 0 삽입
	answer.push_back(-1);	// 계산하기 편하려고 -1 한거고 나중에 다 0으로 바꿔줄거다.

	// answer.resize(cnt); 해주기위해서 cnt를 구한다.
	if (n == 1)
		cnt = 1;
	else {
		cnt = 1;	// 이거 안해주면 아래 계산 안된다.
		for (int i = 1; i < n; i++)
		{
			cnt = cnt * 2 + 1;
		}
	}

	answer.resize(cnt);	// resize(cnt) 해주는 이유는 answer[i] = 1; 이런식으로 인덱스로 편하게 접근하기 위해서


	if (n == 1)
	{
		answer[0] = 0;
		return answer;
	}
	else {	// n >= 2
		answer[1] = -1;
		answer[2] = 1;

		if (n == 2)	// n = 2 이면 바로 끝내고 n >= 3 이면 밑에 for문 수행한다.
			answer;
	
		cnt = 3;
		for (int i = 2; i < n; i++)	// i 는 각 접은번째의 계산을 위해서(인자로 활용 안됨)
		{
			cnt = cnt * 2 + 1;
			answer[cnt/2] = -1;	// ★ 가운데는 무조건 0 이다.

			for (int j = cnt/2 + 1, k = cnt/2 -1; j < cnt; j++, k--)
			{
				answer[j] = answer[k]*(-1);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == -1)
			answer[i] = 0;
	}

	return answer;
}
int main()
{
	int n;
	
	cin >> n;

	for (int i = 0; i < solution(n).size(); i++)
	{
		cout << solution(n)[i] << " ";
	}

	return 0;
}