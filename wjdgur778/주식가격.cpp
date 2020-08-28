#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;



int solution() {



	return 0;
}
int main() {
	vector<int> arr(5);
	stack<int> s;
	vector<int>answer(5);


	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < arr.size()-1; i++) {

		s.push(i);

	//	if (i == arr.size() - 1) break;

		while(arr[s.top()] > arr[i+1] && ! s.empty()) {
			answer[s.top()] = i+1 - s.top();	
			s.pop();
		}
	}
	while (!s.empty()) {
		answer[s.top()] = arr.size() - s.top() - 1;
		s.pop();
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i]<<endl;
	}
	return 0;
}