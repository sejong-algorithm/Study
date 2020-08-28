#include <string>
#include <vector>
#include<iostream>
#include<set>
using namespace std;
vector<int>arr(8);
vector<bool>Select(8);
vector<int>V;
set<char> alpha;
vector<string> dat;
int Size;
int n;
int ans = 0;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void compare() {
    vector<int>check(26, 0);
    int i = 0;
    for (auto it = alpha.begin(); it != alpha.end(); it++) {
        check[*it - 65] = V[i];
        i++;
    }
    for (int i = 0; i < 2; i++) {
        if (dat[i][3] == '=') {
            if (abs(check[dat[i][0]-65] - check[dat[i][2] - 65]) != 1) {
                return;
            }
        }
        else if (dat[i][3] == '<') {
            if (abs(check[dat[i][0] - 65] - check[dat[i][2] - 65]) >= (dat[i][4] - '0') + 1) {
                return;
            }
        }
        else {
            if (abs(check[dat[i][0] - 65] - check[dat[i][2] - 65]) <= (dat[i][4] - '0') + 1) {
                return;
            }
        }
    }
    ans++;
    return;
}
void dfs(int cnt) {
    if (cnt == Size) {
        compare();
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (Select[i] == true)continue;
        Select[i] = true;
        V.push_back(arr[i]);
        dfs(cnt + 1);
        V.pop_back();
        Select[i] = false;
    }
}




int solution(int n, vector<string> d) {
    int answer = 0;
    //순열로 돌리면서 조건에 맞는것만 카운트?
    dat.assign(d.begin(), d.end());

    for (int i = 0; i < 8; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        alpha.insert(dat[i][0]);
        alpha.insert(dat[i][2]);
    }
    Size = alpha.size();

    dfs(0);
    cout << ans;

    return answer;

}
//N~F=0, R~T>2
void main()
{
    vector<string>d;
    string a;
    d.push_back("N~F=0");
    d.push_back("N~F>2");

    solution(2,d);

}