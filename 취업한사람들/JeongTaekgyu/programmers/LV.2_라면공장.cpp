#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int, vector<int>, less<int>> pq;	// default는 내림차순 less<>
	int j = 0;

	j = 0;
	while (stock < k)
	{
		for (int i = j; i < dates.size() && stock >= dates[i]; i++)
		{
			pq.push(supplies[i]);
			j = i + 1;
		}
		stock += pq.top();
		pq.pop();

		answer++;
	}

	return answer;
}
int main()
{
	vector<int> dates;
	vector<int> supplies;
	int stock;
	int size;
	int k;
	int temp;

	cin >> stock;
	cin >> size;


	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		dates.push_back(temp);
	}
	
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		supplies.push_back(temp);
	}

	cin >> k;

	cout << solution(stock, dates, supplies, k) << endl;

	return 0;
}