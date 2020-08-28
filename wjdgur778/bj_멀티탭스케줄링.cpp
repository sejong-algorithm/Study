#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	int n, k;
	int answer = 0;

	cin >> n >> k;
	set <int> tmp;
	vector<int> vec;
	vector<int> m_tap;

	int s = 0;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		//비어있는곳 꽂자
		if (tmp.size() != n) {
			if (tmp.find(a) == tmp.end()) {	
				tmp.insert(a);
				m_tap.push_back(a);
				if (tmp.size() == n) s = i + 1;
			}
		}
	}

	for (int i = 0; i < m_tap.size(); i++) {
		cout <<"처음 멀티 : "<< m_tap[i] << " ";
		cout << endl;
	}

	//교체 알고리즘 
// tap에 꽂혀있는 기기중 가장 나중에 쓸 기기를 뽑자
//2 15
//3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
//n개의 tap안에 꽂혀있는 친구들중 가장 나중에 사용될 친구를 뺀다

	for (; s < k; s++) {
		bool check = true;
		bool ff = true;

		pair<int, int> max;
		max.first = 0;
		max.second = 0;

		for (int i = 0; i < n; i++) {
			if (m_tap[i] == vec[s]) {
				check = false;
				break;
			}
		}

		//같은게 없다면
		if (check) {
			for (int j = 0; j < n; j++) {
				bool f = true;
				for (int jj = s + 1; jj < k; jj++) {
					if (m_tap[j] == vec[jj]) {
						f = false;
						//처음엔 넣고
						if (max.second == 0) {
							max.first = j;
							max.second = jj;
						}
						//들어가 있으면 비교해서 최대를 갖고 있자
						else {
							if (max.second < jj) {
								max.second = jj;
								max.first = j;
							}
						}
						//가장 주의해야할 break라고 생각
						// 바로 위의 if 문  " if(max.second < jj) "이 성립하는 경우에 break를 한다면 
						// 스케줄링상 먼저 와야 할 기기를 나중으로 알아버림
						// ex) [1,2,3]  4 1 2 3 4 1 
						// 위의 경우 1이 가장 빨리 나오기 때문에 1을 뽑으면 안되지만 나중에 나온 1을 보고
						// 가장 나중에 온것은 1 이라고 판단하게 된다.
						break;
					}
				}
				//같은게 하나도 없을시
				if (f) {
					answer++;
					m_tap[j] = vec[s];
					ff = false;
					break;
				}
			}
			// 같은게 있을시 스케줄링상 우선순위가 가장 낮은 idx (max.first)에 비교대상을 넣어준다.
			if (ff) {
				m_tap[max.first] = vec[s];
				answer++;
			}

			for (int ii = 0; ii < n; ii++) {
				cout << m_tap[ii] << " ";
			}
			cout << endl;
		}


	}


	cout << answer;
	return 0;
}