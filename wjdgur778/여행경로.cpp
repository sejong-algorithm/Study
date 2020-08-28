#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<string, vector<pair<string,bool>>> c_map;
vector<bool> check;
vector<string> tmp;
vector<string> answer;
bool f = true;
int total = 0;
void dfs(string s) {
	cout << s << endl;
	tmp.push_back(s);

	if (tmp.size() == total) {
		if (f) {
			answer = tmp;
			f = false;
			return;
		}
		else {
			answer = answer > tmp ? tmp : answer;
		}
		return;
	}

	for (int i = 0; i < c_map[s].size(); i++) {
		if (c_map[s][i].second == false) {
			c_map[s][i].second = true;
			dfs(c_map[s][i].first);
			tmp.pop_back();
			c_map[s][i].second= false;
		}

	}

}
//map<string, vector<pair<string,bool>>> c_map;


vector<string> solution(vector<vector<string>> tickets) {
	//	vector<string> answer;
	total = tickets.size()+1;
	//make map

	for (int i = 0; i < tickets.size(); i++) {
		if (c_map.find(tickets[i][0]) == c_map.end()) {
			vector<pair<string,bool>> v;
			v.push_back(make_pair(tickets[i][1],false));
			c_map.insert(make_pair((tickets[i][0]), v));
		}
		else {
			c_map[tickets[i][0]].push_back(make_pair(tickets[i][1],false));
		}
	}
	
	dfs(tickets[0][0]);
	
	return answer;
}


int main() {

	solution({ {"ICN","SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });

	return 0;
}
