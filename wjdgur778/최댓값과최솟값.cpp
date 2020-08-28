#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    int cnt = 0;
    int i;
    int big=1231;
    int small=0;
    string tmp;
    for (i = 0;i < s.size();i++) {

        if (s[i] != ' ') {
            tmp += s[i];
        }
        else {
            cnt++;
            if (cnt == 1) {
                big = stoi(tmp);
                small = stoi(tmp);
                tmp.clear();
            }
            else {
                big = max(stoi(tmp), big);
                small = min(stoi(tmp), small);
                tmp.clear();
            }
        }
        if (i ==int( s.size() - 1)) {
            big = max(stoi(tmp), big);
            small = min(stoi(tmp), small);
        }
    }
    answer += to_string(small);
    answer += " ";
    answer += to_string(big);

    return answer;
}
int main() {

    string s;
    getline(cin,s);
    cout<<solution(s);
    return 0;
}