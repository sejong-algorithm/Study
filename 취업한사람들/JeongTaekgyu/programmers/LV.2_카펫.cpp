#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int block_num = brown + red;
	int t_red;
	int t_brown;
	//red = (가로 - 2)*(세로 - 2);
	//brown = 가로 * 세로 - red;

	// 격자의 행렬은 3*3 이 가장 작기 때문에 3*3 부터 시작한다.
	// 또한 가로 >= 세로 이기 때문에 wid = hei 부터 시작한다.
	for (int hei = 3; hei <= block_num/sqrt(block_num); hei++)
	{	// 세로 역시 가장 극단적인 경우는 가로 == 세로 이기 때문에 hei < block_num / block_num의 제곱근 까지 보면된다. 
		for (int wid = hei; wid <= block_num/3; wid++)
		{	// 가장 극단적인 경우를 생각하면 가로는 조건까지 가능하고 세로가 3인경우를 생각해보면 wid <= block_num/3 까지 가능하다
			t_red = (wid - 2)*(hei - 2);
			t_brown = (wid*hei) - t_red;
			if(t_brown == brown && t_red == red)
			{
				answer.push_back(wid);
				answer.push_back(hei);
			}
			
		}
	}

	return answer;
}
int main()
{
	int brown, red;

	cin >> brown;
	cin >> red;

	for (int i = 0; i < 2; i++)
	{
		cout << solution(brown, red)[i] << endl;
	}
	return 0;
}