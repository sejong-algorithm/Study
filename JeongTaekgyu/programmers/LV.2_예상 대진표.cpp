#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while (a != b)
	{
		// 다음라운드에 가지게 될 변호를 삽입한다.
		if (a % 2 == 0)
			a = a / 2;
		else if (a % 2 == 1)
			a = a / 2 + 1;
		if (b % 2 == 0)
			b = b / 2;
		else if (b % 2 == 1)
			b = b / 2 + 1;

		answer++;
	}

	return answer;
}
int main()
{
	int n;
	int a, b;

	cin >> n;
	cin >> a;
	cin >> b;

	cout << solution(n, a, b) << endl;

	return 0;
}