#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 재귀의 피보나치
/*int fibo(int n)
{
	// 이 문제는 n이 2이상만이 입력된다 f(n) = f(n-1) + f(n-2)
	// f(0) = 0,  f(1) = 1
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fibo(n - 1) + fibo(n - 2);
}*/

int solution(int n) 
{
	int answer = 0;
	int a = 0;
	int b = 1;
	
	for (int i = 0; i < n-1; i++)
	{
		answer = (a + b) % 1234567;
		a = b % 1234567;
		b = answer % 1234567;
	}

	return answer;
}
int main()
{
	int n;

	cin >> n;
	cout << solution(n) << endl;

	return 0;
}	