#include<iostream>
#include<vector>
using namespace std;

vector<bool> vec(10, false);
int m = 3;

void print() {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	return;
}
void dfs(int idx, int n) {

	if (n == m) {
		print();
		return;
	}
	if (idx == vec.size() -1)return;
	vec[idx] = true;
	dfs(idx+1,n+1);
	vec[idx] = false;
	dfs(idx + 1, n);

}

int main()
{
	dfs(0,0);


}
