#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());	// default는 오름차순
	sort(B.begin(), B.end(), greater<int>());	// 내림차순		
	// 오름차순과 내림차순으로 해줬기 때문에 밑에서 그냥 똑같은 인덱스로 곱하면 된다.

	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[i];
	}

	return answer;
}
int main()
{
	vector <int>A;
	vector <int>B;
	int n;
	int tmp;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}

	cout << solution(A, B) << endl;

	return 0;
}