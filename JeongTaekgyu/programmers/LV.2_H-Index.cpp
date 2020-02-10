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
	����� ���� ������
	case 1. citations.size() == 1 �̸鼭 citation[0] >= 1 �ΰ��
	case 2. citations.size() == 1 �̸鼭 citation[0] == 0 �ΰ��
	case 3. citations.size() >= 2 �̸鼭 citation�� �� ���� ��� 0�ΰ��
	case 4. citations.size() >= 2 �̸鼭 citation�� �� ���� ��� i(�ε���)���� ū ���
	case 5. �� ��
	*/

	// case 1. ó��
	if (citations.size() == 1 && citations[0] >= 1)
	{
		answer = 1;
		return answer;
	}

	for (int i = 0; i < citations.size(); i++)
	{
		// case 2.3.5 ó��  i = 0 , citations[0] = 0 �̸� answer = 0 ��
		if (i >= citations[i])
		{
			answer = i;
			break;
		}
		// case 4. ó��
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