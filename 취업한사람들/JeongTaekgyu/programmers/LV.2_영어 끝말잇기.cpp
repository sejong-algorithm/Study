#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2);
	int wrong = 0;
	//int k = 0;
	int cnt = 0;

	answer[0] = 0;
	answer[1] = 0;

	for (int i = 1; i < words.size(); i++)
	{
		// 앞의 마지막 글자와 지금의 첫번째 글자가 다르면 틀렸다.
		if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
		{
			answer[0] = i % n + 1;	// 몇번째 사람인지
			answer[1] = i / n + 1;	// 틀린사람의 끝말잇기 횟수
			break;
		}

		for (int j = 0; j < i; j++)
		{
			if (i != j && words[i].compare(words[j]) == 0)	// 똑같은게 나오면 틀렸다.
			{
				answer[0] = i % n + 1;	// 몇번째 사람인지
				answer[1] = i / n + 1;	// 틀린사람의 끝말잇기 횟수
				wrong = 1;
				break;
			}
		}
		if (wrong)
			break;
	}

	// 틀린사람의 끝말잇기 참여 횟수를 계산하는 과정을 whlie문으로 (위에서 i /n + 1)
	// 이건 반복문 하나 쓰므로 비효율적
	/*
	k = 0;
	while (k < answer[1])
	{
		k += n;
		cnt++;
	}
	answer[1] = cnt;	// 틀린사람의 끝말잇기 횟수
	*/

	return answer;
}

int main()
{
	vector<string> words(10);	// cin 할때 편하게 하려고 미리 크기 정했다.
	int i = 0;
	int n;
	int size = 0;

	cin >> n;

	// 몇개 들어있는지 알수 없는데 그냥 10개 넣자ㅇㅇ
	for (int i = 0; i < 10; i++)
	{
		cin >> words[i];
	}

	for (int i = 0; i < solution(n, words).size(); i++)
	{
		cout << solution(n, words)[i] << endl;
	}

	return 0;
}