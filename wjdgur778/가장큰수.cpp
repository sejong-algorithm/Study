#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// "numbers" vector�� Ư���� �켱������ ���ؼ� ������ string�� push_back �Ѵ�.
// ���� ���� -> 

bool comp(string a, string b) {
	return a + b > b + a;
}



string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;
	for (int i = 0; i < numbers.size(); i++) {
		tmp.push_back(to_string(numbers[i]));
	}
	sort(tmp.begin(), tmp.end(), comp);
	cout << tmp[0];
	if (tmp[0] == "0") return 0;
	for (int i = 0; i < numbers.size(); i++) {
		answer += tmp[i];
	}
	return answer;
}

int main() {

	solution({3,30,34,5,9});

	return 0;
}