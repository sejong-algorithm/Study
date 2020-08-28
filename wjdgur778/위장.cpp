#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int n = 0;
int answer = 0;
int cnt = 1;
vector<int>v;
vector<vector<string>> clothes;
unordered_map<string, int> h;
unordered_map<string, int> ::iterator iter;
bool check[4] = { false };
int level = 0;

/*
void dfs(unordered_map<string, int> ::iterator iter, int cnt,vector<bool>Select) {
    if (level == n) {
        level -= 1; return;
    }
    else { 
        level += 1;
    }
    if (iter == h.end())return;

    cnt *= iter->second;
    answer += cnt;

  

    for (unordered_map<string, int> ::iterator jter = iter; jter!= h.end();j++) {
        if (Select[i] == true)continue;
        Select[i] = true;
        dfs(++iter, cnt,Select);
        Select[i] = false;
    }
}


int solution() {
    for (int i = 0;i < clothes.size();i++) {
        h.insert(make_pair(clothes[i][1], 0));
    }
    for (int i = 0;i < clothes.size();i++) {
        h[clothes[i][1]] += 1;
    }
    iter = h.begin();
    for (int i = 1;i <=4;i++) {
        vector<bool> Select(7, false);
        n = i;
        dfs(iter, 1,Select);
    }
    return answer;
}
*/

void dfs(int idx,int Cnt, vector<bool>Select, int sum)
{
    if (Cnt == n) {
        answer += sum;
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        sum *= v[i];
        dfs(i,Cnt + 1, Select, sum);
        sum /= v[i];
        Select[i] = false;
    }
}


int solution() {

    for (int i = 0;i < clothes.size();i++) {
        h.insert(make_pair(clothes[i][1], 0));
    }
    for (int i = 0;i < clothes.size();i++) {
        h[clothes[i][1]] += 1;
    }
    for (iter = h.begin();iter != h.end();iter++) {
        v.push_back(iter->second);
    }
    for (int i = 1;i <= h.size();i++) {
        n = i;
        vector<bool> Select(7, false);
        dfs(0,0, Select, 1);
    }
    return answer;

}
void main() {
    for (int i = 0;i < 5;i++) {
        string a;
        string b;
        vector <string>s;
        cin >> a >> b;
        s.push_back(a);
        s.push_back(b);
        clothes.push_back(s);
    }
    
    cout<<solution();



}