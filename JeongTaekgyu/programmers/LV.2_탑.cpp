#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size(),0);	// 벡터의 크기가 할당이 안된채로 answer[i] = 4; 이런식으로 삽입하면 당연히 삽인안되니까 미리 공간을 할당해줌
	int left_tower_chk;


	left_tower_chk = 0;
	for (int i = heights.size()-1; i > 0 ; i--)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (heights[j] > heights[i])// 왼쪽으로 가면서 자기보다 큰 탑 나오면
			{
				answer[i] = j+1;		// 큰탑의 위치를 삽입하고
				left_tower_chk = 1;		// 왼쪽에서 자기보다 큰탑을 발견했다는 신호를 발생시킨다
				break;
			}
		}
		if (left_tower_chk == 0)// 왼쪽에 자기보다 큰 탑이 없으면
			answer[i] = 0;
		else
			left_tower_chk = 0;	// 왼쪽에 자기보다 큰 탑이 있으면 다음 탐색을 위해  왼쪽에 자기 보다 큰 탑이 없는 상태로 만들어준다
	}

	return answer;
}
int main()
{
	vector<int> input;
	int n;
	int temp;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < n; i++)
		cout << solution(input)[i] << " ";
	
	return 0;
}