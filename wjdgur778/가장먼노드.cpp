#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {

    int answer = 0;
    int pre = 0;
    vector<vector<int>> tmp(20001, vector<int>(0, 0));
    vector<bool> check(20001, false);
    queue<int> q;

    for (int i = 0; i < edge.size(); i++) {
        tmp[edge[i][0]].push_back(edge[i][1]);
        tmp[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int cnt = 0;
        int q_size = q.size();
        for (int j = 0; j < q_size; j++) {

            int size = tmp[q.front()].size();

            for (int i = 0; i < size; i++) {
                if (check[tmp[q.front()][i]] == false) {
                    check[tmp[q.front()][i]] = true;
                    q.push(tmp[q.front()][i]);
                    cnt++;
                }
            }
            q.pop();
        }
        if (q.empty())break;
        pre = cnt;
    }
    answer = max(answer, pre);
    return answer;
}
