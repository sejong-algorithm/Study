#include <iostream>

using namespace std;
int solution(int n)
{
	int sum = 0;
	int temp;

	temp = n;

	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}

	return sum;
}
int main()
{
	int n;
	
	cin >> n;

	cout << solution(n) << endl;

	return 0;
}