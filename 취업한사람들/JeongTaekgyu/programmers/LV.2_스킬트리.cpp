#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int cnt;
	int fail = 0;

	// i,k  : skill_trees[i][k]
	// j    : skill[j];
	// cnt  : skill[j] == skill_trees[i][j]
	// fail : 순서가 안맞을 때 
	for (int i = 0; i < skill_trees.size(); i++)
	{
		cnt = 0;
		fail = 0;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			for (int k = cnt; k < skill.size(); k++)	// k = cnt 한 이유는 앞에 skill 에서 검사한거 또 검사할 필요없어서
			{
				if (skill_trees[i][j] == skill[k])
				{
					if (k == cnt)
					{
						cnt++;	// 그 다음 순서도 맞는지 체크해 주려고
						break;
					}
					else {
						fail = 1;
						break;
					}
				}
			}
			if (fail)
				break;
		}
		if ( fail == 0 )
		{
			cout << skill_trees[i] << endl;
			answer++;
		}
	}

	return answer;
}
int main()
{
	string skill="CBD";
	vector<string> skill_trees;
	
	cout << skill << endl;
	cout << skill.size() << endl;

	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");

	for (int i = 0; i < skill_trees.size(); i++)
		cout << skill_trees[i] << endl;
	cout << skill_trees.size() << endl;
	// 왜 skill_trees(4); 이랑 skill_trees; 한거랑 출력이 다르지?
	// skill_trees(4)은 4칸 엔터돼서 출력되고
	// skill_trees; 은 엔터없이 출력되네..
	// ★ ★ ★ 아아아아아아!!!! 최초에 vector<string> skill_trees(4); 로 선언했으면 
	// 4개의 공간이 선언되고 그 후에 push_back 했으니까 4개의 공간도 출력되지 아하!!! 

	cout << endl << solution(skill, skill_trees) << endl;


	/*for(int i = 0; i < 3; i++)
		cin >> skill[i];

	for (int i = 0; i < 4; i++)
		getline(cin, skill_trees[i]);

	cout << endl;

	for (int i = 0; i < 3; i++)
		cout << skill[i] << endl;;

	for (int i = 0; i < 4; i++)
		cout << skill_trees[i] << endl;
		*/
}