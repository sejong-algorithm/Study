#include <iostream>

using namespace std;
int solution(int n)
{
	int answer = 0;

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	while (n > 0) {
		answer += n % 10;
		n /= 10;
	}
	cout << "Hello Cpp" << endl;

	return answer;
}