#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
dfs로 풀자
dp
                


*/

int base = 0;
int target = 0;
int answer = 9999999999;
int N;
void dfs(int cnt ,int n) {
	if (n < 0) return;
	if (cnt > 8) return;

	if (n == target) {
		answer = min(answer , cnt);
		return;
	}
	int tmp = 0;

	for (int i = 0; i <8; i++) {
		tmp = (tmp* 10) + base;
		//cout << tmp << endl;
		dfs(cnt + 1 + i, n + tmp);
		dfs(cnt + 1 + i, n - tmp);
		dfs(cnt + 1 + i, n * tmp);
		dfs(cnt + 1 + i, n / tmp);
	}



}


int solution(int n, int number) {
	base = n;
	target = number;
	dfs(0, 0);
	cout << answer;
	return 0;

}



int main() {
	solution(5,12);

	return 0;
}
//#include <string>
//#include <vector>
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//
////bfs로는 안되는가?
//
//vector <int> check(32001, -1);
//queue<int> q;
//int target = 0;
//
//int solution(int N, int number) {
//
//    //init
//    int tmp = N;
//    int a = 1;
//    int answer = 9;
//    while (tmp < 32000) {
//        check[tmp]=a;
//        tmp += N*pow(10,a);
//        a++;
//    }
//
//    /*
//    N,NN,NNN,NNNN 은 특수한 친구들
//    */
//
//    q.push(N);
//
//    while (!q.empty()) {
//        int size = q.size();
//        
//        for (int i = 0; i < size; i++) {
//           // cout << q.front() << endl;
//     
//            //plus
//            if (q.front() + N <= 32000) {
//                //구해보지 않은것
//                if (check[q.front() + N] == -1) {
//                    check[q.front() + N] = check[q.front()] + 1;
//                    q.push(q.front() + N);
//
//                }
//                //구했다면 min 값을 가져가자
//                else {
//                    check[q.front() + N] = check[q.front() + N] >= check[q.front()] + 1 ? check[q.front()] + 1 : check[q.front() + N];
//                    if ((q.front() + N) / N == 11 || (q.front() + N) / N == 111 || (q.front() + N) / N == 1111 || (q.front() + N) / N == 11111) {
//                        q.push(q.front() + N);
//                    }
//                }
//            }
//            //minus
//            if (q.front() - N > 0) {
//                if (check[q.front() - N] == -1) {
//                    check[q.front() - N] = check[q.front()] + 1;
//                    q.push(q.front() - N);
//                }
//                else {
//                    check[q.front() - N] = check[q.front() - N] >= check[q.front()] + 1 ? check[q.front()] + 1 : check[q.front() - N];
//                    if ((q.front() - N) / N == 11 || (q.front() - N) / N == 111 || (q.front() - N) / N == 1111 || (q.front() - N) / N == 11111) {
//                        q.push(q.front() - N);
//                    }
//                }
//            }
//            //multiply
//            if (q.front() * N <= 32000) {
//                if (check[q.front() * N] == -1) {
//                    check[q.front() * N] = check[q.front()] + 1;
//                    q.push(q.front() * N);
//                }
//                else {
//                    check[q.front() * N] = check[q.front() * N] >= check[q.front()] + 1 ? check[q.front()] + 1 : check[q.front() * N];
//                    if ((q.front() * N )/ N == 11 || (q.front() * N) / N == 111 || (q.front() * N) / N == 1111 || (q.front() * N) / N == 11111) {
//                        q.push(q.front() * N);
//                    }
//                }
//            }
//            //division
//            if (q.front() / N > 0 ) {
//                if (check[q.front() / N] == -1) {
//                    check[q.front() / N] = check[q.front()] + 1;
//                    q.push(q.front() / N);
//
//                }
//                else {
//                    check[q.front() / N] = check[q.front() / N] >= check[q.front()] + 1 ? check[q.front()] + 1 : check[q.front() / N];
//                    if ((q.front() / N) / N == 11 || (q.front() / N) / N == 111 || (q.front() / N) / N == 1111 || (q.front() / N) / N == 11111) {
//                        q.push(q.front() / N);
//                    }
//                }
//            }
//            if (q.front() == number) {
//                answer = min(answer, check[q.front()]);
//            }
//            q.pop();
//        }
//
//    }
//    if (answer > 8) return -1;
//    else return answer;
//}
//
//int main() {
//
//   cout<< solution(5, 624);
//    return 0;
//}