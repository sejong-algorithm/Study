#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

string numbers;
int answer = 0;
set <int> s;
vector<int> arr;
string V;
int n;

int a;
void dfs(int Cnt,vector<bool>Select)
{
	if (Cnt == n)
	{
		a = stoi(V);
		if (a == 1)return;
		if (a % 2 == 0)return;
		for (int i = 2; i * i <= a; i++) {
			if (a%i == 0)return;
		}
		s.insert(a);
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;
		V += to_string(arr[i]);
		dfs(Cnt + 1,Select);
		V.pop_back();
		Select[i] = false;
	}
}

int main(void)
{
	
	cin >> numbers;
	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(numbers[i] - '0');
		if (arr[i] == 2 || arr[i] == 3 || arr[i] == 5|| arr[i] == 7)
		{
			s.insert(arr[i]);
		}

	}
	for (int i = 2; i <= numbers.size(); i++) {
		n = i;
		vector<bool> Select(7, false);
		V.clear();
		dfs(0,Select);
	}
	answer = s.size();

	cout << answer;
	return 0;

}

