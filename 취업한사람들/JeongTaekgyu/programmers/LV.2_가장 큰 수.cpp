#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;

	for (int i = 0; i < numbers.size(); i++)
		temp.push_back(to_string(numbers[i]));

	sort(temp.begin(), temp.end(), comp);

	for (int i = 0; i < numbers.size(); i++)
		answer += temp[i];

	if (answer[0] == '0')
		return "0";

	return answer;
}
int main()
{
	int size;
	int temp;
	vector<int> numbers;

	cin >> size;

	for (int i = 0; i < size; i++)
	{ 
		cin >> temp;
		numbers.push_back(temp);
	}

	cout << solution(numbers) << endl;

	return 0;
}