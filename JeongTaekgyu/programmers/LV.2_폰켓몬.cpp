#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
	set<int> s;
	int answer = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		s.insert(nums[i]);
	}

	if (s.size() <= nums.size() / 2)
		answer = s.size();
	else if (s.size() > nums.size() / 2)
		answer = nums.size() / 2;

	return answer;
}

int main(void) {
	
	vector <int> nums;
	int n;
	int temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	cout << solution(nums) << endl;

	return 0;
}