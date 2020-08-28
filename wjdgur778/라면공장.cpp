#include <string>
#include<iostream>
#include <vector>
#include<queue>
using namespace std;

int solution(int stock, vector<int> d, vector<int> su, int k) {
    int answer = 0;
    int flour = stock;
    priority_queue <int, vector<int>> q;
    for (int i = 0; i < d.size(); i++) {
        if (flour >= d[i]) {
            q.push(su[i]);
        }
        else {
            answer++;
            flour += q.top();
            q.pop();
            if (flour >= d[i]) {
                q.push(su[i]);
            }
        }
        if (flour >= k)return answer;
    }
    while (flour < k) {
        answer++;
        flour += q.top();
        q.pop();
    }
    return answer;
}
int main() {

    vector<int>a(3,0);
    vector<int>b(3,0);
    a[0] = 4;
    a[1] = 5;
    a[2] = 7;

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;

    cout << solution(4,a,b,10);
}