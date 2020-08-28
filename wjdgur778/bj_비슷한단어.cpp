#include<iostream>
#include<vector>
#include<string>activecf.h
using namespace std;

vector<vector<vector<int>>>ck_arr(26);

int check(string a, string b,int target) {

	if (a.size() != b.size())return 0;
	else {
		for (int i = 0; i < a.size(); i++) {



		}
	}
}


int main() {
	
	int n;
	int answer;
	cin >> n;
	
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].size(); j++) {
			ck_arr[i][arr[i][j] - 97].push_back(j);
		}
	}

	cout << arr[0][0] - arr[1][0];
		for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
		//	answer += check(arr[i], arr[j],i);
		}

	}
	


	return 0;
}