#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

	vector<vector<int>> accum(triangle.size(), vector<int>(triangle.size()));
	// 2차원 벡터의 공간 할당 vector<vector<int>> temp(행 크기, vector<int>(열 크기));

	accum[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				accum[i][j] = accum[i - 1][j] + triangle[i][j];
			}
			else if (j == i)
			{
				accum[i][j] = accum[i - 1][j - 1] + triangle[i][j];
			}
			else {
				accum[i][j] = max(accum[i - 1][j - 1] + triangle[i][j], accum[i - 1][j] + triangle[i][j]);
			}

			if (i == triangle.size() - 1) // 마지막 행에서 최댓값을 넣어준다.
				answer = max(answer, accum[i][j]);
		}
	}

    return answer;
}
int main()
{
	vector<vector<int>> triangle
	= { {7},
		{3, 8},
		{8, 1, 0},
		{2, 7, 4, 4},
		{4, 5, 2 ,6, 5}
	};

	cout << solution(triangle) << endl;

	return 0;
}