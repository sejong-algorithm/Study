#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long mul = 1;
	vector <long long> arr;

	while (n != 0)
	{
		arr.push_back(n % 10);
		n /= 10;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		answer += arr[i] * mul;
		mul *= 10;
	}

	return answer;
}
int main()
{
	long long n;

	cin >> n;

	solution(n);

	return 0;
}