#include<iostream>
#include<vector>
using namespace std;
/*
돌 게임은 두 명이서 즐기는 재밌는 게임이다.

탁자 위에 돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 돌은 1개 또는 3개 가져갈 수 있다. 마지막 돌을 가져가는 사람이 게임을 이기게 된다.

두 사람이 완벽하게 게임을 했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 먼저 시작한다
*/
int main() {
	int n; 
	cin >> n;
	//1 또는 3
	//first -> SK           
	//second -> CY
	//ex) 10 
	// 마지막만 보면 되지 않을까?
	// 3 3 3 1 홀수개면 SK , 짝수개면 CY가 이긴다.
	// 4일때 CY
	// 5일때 SK
	// 1일때 SK
	// 2일때 CY
	// 3일때 SK
	// 10이면? 1 3
	// 12일때? 1 1 3 3 1 1 1 1 
	if (n % 2 == 0)cout << "CY";
	else cout << "SK";
	return 0;
}