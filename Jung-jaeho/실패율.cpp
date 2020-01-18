#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> p1, pair<double, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    vector<pair<double, int>> failure;
    for(int i = 0 ; i<= N; i++){
        failure.push_back(make_pair(0,0));
    }
    for(int i = 0 ; i < stages.size(); i++)
    {
        int num = stages[i];
        failure[stages[i]-1].first += 1;
        while(num > 0){
            failure[num - 1].second += 1;
            num -= 1;
        }
    }
    for( int i = 0 ; i < N ; i++){
        if(failure[i].second == 0)
            failure[i] = make_pair(0, i);
        else
            failure[i] = make_pair(failure[i].first / failure[i].second, i);
    }
    failure.pop_back();
    sort(failure.begin(), failure.end(), cmp);
    for(int i = 0 ; i< N ; i++){
        answer.push_back(failure[i].second+1);
    }
    return answer;
}