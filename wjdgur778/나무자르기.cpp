#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n=0;
	int m=0;
	int answer=0;
	int s=1;
	int e=0;
	int mid;
	vector<int> vec;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		e = max(e, a);
		vec.push_back(a);
	}

	while (s <= e) {
		long long sum=0;
		mid = (s + e) / 2;

		for (int i = 0; i < n; i++) {
			if(vec[i] - mid >=0) sum  += (vec[i] - mid);
		}
		cout << "sum : "<<sum<<" mid : "<<mid<<endl;
		if (sum >= m) {
			answer = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
		
	}
	cout << answer;
	return 0;
}

