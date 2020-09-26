#include<iostream>
using namespace std;


//º°Âï±â -10
char map[6561][6561];
int dx[8] = { -1,1,0,1,-1,0,1,-1 };
int dy[8] = { -1,1,1,0,0,-1,-1,1 };
void solution(int n, int x, int y)
{
	if (n == 3) {

		for (int i = 0; i < 8; i++) {
			map[x + dx[i]][y + dy[i]] = '*';
		}
		return;
	}

	solution(n / 3, x - n / 3, y - n / 3);
	solution(n / 3, x, y - n / 3);
	solution(n / 3, x - n / 3, y);
	solution(n / 3, x + n / 3, y + n / 3);
	solution(n / 3, x + n / 3, y);
	solution(n / 3, x, y + n / 3);
	solution(n / 3, x - n / 3, y + n / 3);
	solution(n / 3, x + n / 3, y - n / 3);

	return;
}


int main()
{
	int n;
	cin >> n;
	solution(n, n / 2 + 1, n / 2 + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0)map[i][j] = ' ';
			cout << map[i][j];
		}
		if (i != n)
			cout << endl;
	}
	return 0;
}