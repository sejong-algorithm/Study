#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int picture[14][17];
bool check[101][101];
int num = 0;
int c_x;
int c_y;
vector<int> answer(2, 0);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

void dfs(int x, int y) {

	check[x][y] = true;
	num++;

	if (x + 1 < c_x && check[x + 1][y] != true && picture[x][y] == picture[x + 1][y]) {
		dfs(x + 1, y);
	}
	if (x - 1 >=0 && check[x - 1][y] != true && picture[x][y] == picture[x - 1][y]) {
		dfs(x - 1, y );
	}
	if (y + 1 < c_y  && check[x][y + 1] != true && picture[x][y] == picture[x][y + 1]) {
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && check[x][y - 1] != true && picture[x][y] == picture[x][y - 1]) {
		dfs(x, y - 1);
	}

	return;
}


int main() {
	int m;
	int n;
	cin >> m >> n;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> picture[i][j];
		}
	}

	c_x = m;
	c_y = n;

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (check[i][j] == 0 && picture[i][j] != 0) {
				num = 0;
				dfs(i, j);
				answer[0]++;
				answer[1] = max(answer[1], num);
			}
		}
	}
	cout << answer[0] << " " << answer[1];


}1	입출력과 사칙연산	입력, 출력과 사칙연산을 연습해 봅시다. Hello World!	도전중	11	2
2	if문	if문을 사용해 봅시다.	완료	5	5
3	for문	for문을 사용해 봅시다.	완료	11	11
4	while문	while문을 사용해 봅시다.	완료	3	3
5	실습 1	수정 예정	완료	6	6
6	1차원 배열	배열을 사용해 봅시다.	완료	7	7