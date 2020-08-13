#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count, int depth) {
	
	//cout << endl << "count : " << count << ", _____";
	//cout << "depth : " << depth << endl;
	depth++;

	if (count == numbers.size()) 
	{
		if (sum == target)
		{
			answer++;
			//cout << "sum == targer" << endl;
		}
		return;
	}
	//cout << sum << " + " << numbers[count] << ", " << count+1 << "( " << count << " + 1 )" << endl;
	dfs(numbers, target, sum + numbers[count], count + 1, depth);
	//cout << sum << " - " << numbers[count] << ", " << count + 1 << "( " << count << " + 1 )" << endl;
	dfs(numbers, target, sum - numbers[count], count + 1, depth);

}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0, 0);

	return answer;
}

int main()
{
	vector<int> numbers(4);
	int n;

	n = 4;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	cout << solution(numbers, 5) << endl;

	return 0;
}