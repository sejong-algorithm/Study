#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
			sum += i;
	}

	return sum;
}
int main()
{
	int n;
	
	std::cin >> n;
	
	std::cout << solution(n) << std::endl;

	return 0;
}