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
		//����ִ°� ����
		if (tmp.size() != n) {
			if (tmp.find(a) == tmp.end()) {	
				tmp.insert(a);
				m_tap.push_back(a);
				if (tmp.size() == n) s = i + 1;
			}
		}
	}

	for (int i = 0; i < m_tap.size(); i++) {
		cout <<"ó�� ��Ƽ : "<< m_tap[i] << " ";
		cout << endl;
	}

	//��ü �˰��� 
// tap�� �����ִ� ����� ���� ���߿� �� ��⸦ ����
//2 15
//3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
//n���� tap�ȿ� �����ִ� ģ������ ���� ���߿� ���� ģ���� ����

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

		//������ ���ٸ�
		if (check) {
			for (int j = 0; j < n; j++) {
				bool f = true;
				for (int jj = s + 1; jj < k; jj++) {
					if (m_tap[j] == vec[jj]) {
						f = false;
						//ó���� �ְ�
						if (max.second == 0) {
							max.first = j;
							max.second = jj;
						}
						//�� ������ ���ؼ� �ִ븦 ���� ����
						else {
							if (max.second < jj) {
								max.second = jj;
								max.first = j;
							}
						}
						//���� �����ؾ��� break��� ����
						// �ٷ� ���� if ��  " if(max.second < jj) "�� �����ϴ� ��쿡 break�� �Ѵٸ� 
						// �����ٸ��� ���� �;� �� ��⸦ �������� �˾ƹ���
						// ex) [1,2,3]  4 1 2 3 4 1 
						// ���� ��� 1�� ���� ���� ������ ������ 1�� ������ �ȵ����� ���߿� ���� 1�� ����
						// ���� ���߿� �°��� 1 �̶�� �Ǵ��ϰ� �ȴ�.
						break;
					}
				}
				//������ �ϳ��� ������
				if (f) {
					answer++;
					m_tap[j] = vec[s];
					ff = false;
					break;
				}
			}
			// ������ ������ �����ٸ��� �켱������ ���� ���� idx (max.first)�� �񱳴���� �־��ش�.
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