#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solution(vector<vector<int>> board)
{
    int answer = 0;

    if (board.size() == 1 || board[0].size() == 1) {
        for (int y = 0; y < board.size(); ++y)
            for (int x = 0; x < board[0].size(); ++x) {
                if (board[y][x] == 1) return 1;
            }
    }

    for (int y = 1; y < board.size(); ++y) {
        for (int x = 1; x < board[0].size(); ++x) {
            if (board[y][x] != 0) {
                board[y][x] = min(board[y - 1][x - 1], board[y - 1][x]);
                board[y][x] = min(board[y][x], board[y][x - 1]);
                board[y][x]++;
                if (board[y][x] > answer) answer = board[y][x];
            }
        }
    }

    answer *= answer;
    return answer;
}
int main() {
    vector<vector<int>>a(2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }


    solution(a);
}
