#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int check[26] = { 0 };
int answer = 0;

string count;
int solution(string skill, vector<string> tree) {
	answer = tree.size();

	for (int i = 0;i < skill.size();i++) {
		check[skill[i] - 65] = i + 1;
	}
	for (int i = 0;i < tree.size();i++) {
		string count;
		for (int j = 0;j < tree[i].size();j++) {
			count.push_back(tree[i][j]);

			if (check[tree[i][j] - 65] == 0) {
				continue;
			}
			else {
				if (j == 0) {
					if (check[tree[i][j] - 65] != 1) {
						answer -= 1;
						break;
					}
				}
				else {
					int sum = 0;
					for (int k = 0;k < count.size() - 1;k++) {
						sum += check[count[k] - 65];
					}
					int p = check[tree[i][j] - 65];
					if (sum != (p * (p - 1)) / 2) {
						answer -= 1;
						break;
					}
				}
			}
		}
	}
	return answer;
}

int main()
{
	string skill;
	vector<string> tree;
cin >> skill;

	for (int i = 0;i < 1;i++) {
		string a;
		cin >> a;
		tree.push_back(a);
	}
	
	cout<< solution(skill, tree);




	return 0;
}