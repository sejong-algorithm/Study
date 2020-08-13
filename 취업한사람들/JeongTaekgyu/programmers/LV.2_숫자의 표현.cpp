#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int answer = 0;
	int cnt = 0;
	int sum;

	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = i; j <= n; j++)
		{
			sum += j;
			if (sum == n)
			{
				cnt++;
				break;
			}
			else if (sum > n)
			{
				break;
			}
		}
	}

	answer = cnt;
	return answer;
}
int main()
{
	int n;
	
	cin >> n;

	cout << solution(n) << endl;

	return 0;
}