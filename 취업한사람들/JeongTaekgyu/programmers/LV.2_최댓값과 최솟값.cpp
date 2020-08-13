#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	vector<int> a;
	string answer = "";
	int chi;
	int max;
	int min;

	chi = 0;	// 캐릭터 인덱스를 0 으로 초기화
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') 
		{
			a.push_back(stoi(s.substr(chi, i - chi)));
			// cout << chi <<","<< i << ",   "<< stoi(s.substr(chi, i- chi)) << endl;
			// 음 원래 문자열.substr(chi,i)는 chi번째 인덱스부터 i개의 인덱스만큼 반환하는건데
			// stoi(s.substr(chi,i))하면 int 형으로 반환돼서 그런지.. 공백나올때 까지만 반환한다.
			// 또한 s.substr(chi, i - chi)로 해준 이유는 chi인덱스가 정수의 시작인덱스이고 i는 정수가 끝나고 나오는 공백 인덱스 이기 때문에
			chi = i + 1;	// 공백에서 한칸만 뒤로 가면된다.(이 문제는 공백이 한칸이기 때문에)
		}
	}
	a.push_back(stoi(s.substr(chi, s.size())));
	// 으흠 s.size()의 개수만큼 반환하는 이유는 숫자가 가장 적을 때는 두개가 오는데 ex) 4 52341251 이런식으로 올 수 있다.
	// 그래서 안전하게 ㅇㅇ어차피 뒤에 null 만나면 끝나서 낭비되는 공간은 없는건가 ???

	min = a[0];
	max = a[0];
	for (int i = 1; i < a.size(); i++)	// 어차피 0번째 인덱스의 값이 max, min 이라 1번째 인덱스부터 시작함
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	answer += to_string(min);
	answer += " ";
	answer += to_string(max);

	return answer;
}
int main()
{
	string s;
	
	getline(cin, s);

	cout << solution(s) << endl;

	return 0;
}