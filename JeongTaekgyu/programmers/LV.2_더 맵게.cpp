#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int scoville_value(int min, int second_min)
{
	return min + (2 * second_min);
}
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int temp;
	int input;
	priority_queue<int, vector<int>, greater<int>> pq;	// default는 내림차순 less<>

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	// 모든 음식의 scoville 지수가 k 이상이면 된다
	while (pq.top() < K && pq.size() > 1)
	{// 그러므로 가장 작은 값이 k보다 작거나 pq.size() > 1 일 때 계속 섞어야한다.

		temp = pq.top();
		pq.pop();
		input = scoville_value(temp, pq.top());
		//cout << "temp : " << temp << ", pq.top() : " << pq.top() << endl;
		//cout << "input : " << input << endl;
		
		pq.pop(); // 섞으면 2개가 없어져야 하니까 pop()를 두 번 해준다.
		pq.push(input);	// 섞은수를 pq에 삽입한다.

		answer++;
	}

	if (pq.top() < K)
		return -1;

	for (int i = 0; !(pq.empty()); i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	return answer;
}
int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;	// default는 내림차순 less<>
	vector<int> scoville;
	int size_n;
	int temp;
	int k;

	cin >> size_n;
	cin >> k;

	for (int i = 0; i < size_n; i++)
	{
		cin >> temp;
		scoville.push_back(temp);
	}

	cout << endl << solution(scoville, k) << endl;

	return 0;
}