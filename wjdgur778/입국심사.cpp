#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s, e;
    s = 1;
    e = 100000000000000;

    while (s<=e) {
        long long mid = (s + e) / 2;
        long long cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += (mid / times[i]);
        }

        if (n <= cnt) {
            e = mid - 1;
            answer = mid;
        }

        else {
            s = mid + 1;
        }

    }
    return answer;
}

int main() {

    cout<< solution(6, { 7,10 });

	return 0;
}