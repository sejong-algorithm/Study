#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
//2개씩 고르자

bool comp(pair<int,int>a, pair<int,int>b) {

    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // key : 장르
    // value : 재생수 , 고유번호
    map<string,vector<pair<int,int>>> albam;
    //장르
    //총 재생수
    map<string, int> sum;
    for (int i = 0; i < genres.size(); i++) {
        if (albam.find(genres[i]) != albam.end()) {
            albam[genres[i]].push_back(make_pair(plays[i], i));
        }
        else {
            vector<pair<int, int>> tmp;
            tmp.push_back(make_pair(plays[i],i));
            albam.insert(make_pair(genres[i],tmp));
        }
        if (sum.find(genres[i]) != sum.end()) {
            sum[genres[i]] += plays[i];
        }
        else {
            sum.insert(make_pair(genres[i], plays[i]));
        }
    }
// sum 의 백터치환
    vector<pair<int, string>>vec;
    for (auto i = sum.begin(); i != sum.end(); i++) {
        vec.push_back(make_pair(i->second, i->first));
    }
    sort(vec.begin(), vec.end(),greater<pair<int,string>>());

    for (int i = 0; i < vec.size(); i++) {
        sort(albam[vec[i].second].begin(), albam[vec[i].second].end(), comp);
        if (albam[vec[i].second].size() == 1) {
            answer.push_back(albam[vec[i].second][0].second);
        }
        else {
            answer.push_back(albam[vec[i].second][0].second);
            answer.push_back(albam[vec[i].second][1].second);
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return answer;
}

int main() {

    solution({ "classic","pop", "classic","classic","pop" }, {500,600,150,800,2500});   
    return 0;
}