/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;

		vector<int> A;
		vector<int> B;
		int N;
		int K;
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			A.push_back(t);
		}
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			B.push_back(t);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int ii= 0;
		while (ii < K) {
			int tmp = 0;
			tmp = max(A[ii] + B[K -(ii+1)], B[ii] + A[K - (ii + 1)]);
			Answer = max(Answer, tmp);
			ii++;
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer;
	}


	return 0;//Your program should return 0 on normal termination.
}