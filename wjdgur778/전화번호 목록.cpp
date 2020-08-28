#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	vector<string> s;
	string a;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		s.push_back(a);

	}
	sort(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++) {

		cout << s[i]<<endl;
	}

	return 0;
}